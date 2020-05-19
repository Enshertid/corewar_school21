#include "assembler.h"
#include "converter.h"

static void	read_file(t_file *file)
{
	char	*line;
	bool	final_newline_exist;

	int i = 0;
	file->lines = vec_create(80, sizeof(t_vector_char));
	while ((gnl(file->fd, &line, &final_newline_exist)) == GNL_OK)
	{
		i += 1;
//		if (useless_line(line))
//			free(line);
//		else
		vec_pushback(&file->lines, &line);
	}
	if (vec_size(&file->lines) == 0)
		file->status = FILE_EMPTY;
	else if (final_newline_exist == false)
		file->status = FILE_NO_FINAL_NEWLINE;
}

static void	free_file(t_file *file)
{
	const size_t	lines_amount = vec_size(&file->lines);
	const size_t	tokens_amount = vec_size(&file->tokens);
	size_t			line;
	size_t			token_line;

	line = 0;
	while (line < lines_amount)
	{
//		printf("line before free: %s\n", file->lines[line]);
		if (file->lines[line][0] != '\0') // иначе фришится то, что не замолочено (.name / .comment == '\0')
		{
//			printf("freed line:%s\n", file->lines[line]);
			free(file->lines[line]);
		}
		line += 1;
	}
	vec_destroy(&file->lines);
	token_line = 0;
	while (token_line < tokens_amount)
	{
		for (int i = 0; i < vec_size(&file->tokens[token_line]); ++i) {
//			printf("value before free:%s\n", file->tokens[token_line][i].value);
			free(file->tokens[token_line][i].value);
		}
		vec_destroy(&file->tokens[token_line]);
		token_line += 1;
	}
	vec_destroy(&file->tokens);
}

static void	error_handle(const t_file *file, t_validation	*val)
{
	if (file->status == FILE_NO_FINAL_NEWLINE)
	{
		warning_add(ERROR, 3, "File \"", file->name,
					"\" haven\'t final newline");
		val->no_newline_empty = 1;
	}
	else if (file->status == FILE_EMPTY)
	{
		warning_add(ERROR, 3, "File \"", file->name, "\" is empty");
		val->no_newline_empty = 1;
	}
}

 static void print(t_vector_char *lines, t_vector_token *tokens)
 {
 	const char types[10][15] = {
 		"LABEL",
 		"INSTRUCTION",
 		"ARGUMENT",
 		"SEPARATOR",
 		"NAME",
 		"COMMENT",
 		"UNKNOWN",
 		"EMPTY"
 	};

 	for (int row = 0; row < vec_size(&tokens); ++row)
 	{
 		printf("Line %d: %s\n", row, lines[row]);
 		printf("Tokens:\n");
 		for (int col = 0; col < vec_size(&tokens[row]); ++col) {
 			printf("\tType: %s, value: \"%s\"\n", types[tokens[row][col].type],
 											tokens[row][col].value);
 		}
 		printf("\n");
 	}
 }

int	determine_args(uint8_t args_byte, uint8_t *first,
					  uint8_t *second, uint8_t *third)
{
	const uint8_t first_arg = ((args_byte & 0b11000000) >> 6);
	const uint8_t second_arg = ((args_byte & 0b00110000) >> 4);
	const uint8_t third_arg = ((args_byte & 0b00001100) >> 2);

	if (!first_arg)
		return (0);
	*first = first_arg;
	if (!second_arg)
		return (1);
	*second = second_arg;
	if (!third_arg)
		return (2);
	*third = third_arg;
	return (3);
}

void		assembly(t_file *file, t_validation	*validation)
{
	t_vector_char *bytecode;
	file->status = FILE_OK;
	read_file(file);
	if (file->status != FILE_OK)
		error_handle(file, validation);
	else
	{
//		printf("1.line[0]:%s\n", file->lines[0]);
		file->tokens = tokenizer(file->lines, validation);
//		printf("2.line[0]:%s\n", file->lines[0]);
		print(file->lines, file->tokens);
		ft_check_labels(file->tokens, validation);
		ft_check_sizes(file->tokens, validation);
		ft_check_instructions(file->tokens, validation);
//		print(file->lines, file->tokens);
		// tokens_analysis(file);
//		if (file->status == FILE_OK)
//		{
//			bytecode = convert_to_bytecode(file->tokens);
//			write_to_file(file, bytecode, file->tokens);
//		}

	}
	free_file(file);
}
