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
		if (file->copy[line][0] != '\0')
			free(file->copy[line]);
		line += 1;
	}
	vec_destroy(&file->copy);
	vec_destroy(&file->lines);
	token_line = 0;
	while (token_line < tokens_amount)
	{
		for (int i = 0; i < vec_size(&file->tokens[token_line]); ++i) {
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

void		assembly(t_file *file, t_validation	*validation)
{
//	t_vector_char *bytecode;
	file->status = FILE_OK;
	read_file(file);
	if (file->status != FILE_OK)
		error_handle(file, validation);
	else
	{
		file->copy = vec_copy(&file->lines, false); // эксперимент
		file->tokens = tokenizer(file->lines, validation);
		ft_check_labels(file->tokens, validation);
		ft_check_sizes(file->tokens, validation);
		ft_check_instructions(file->tokens, validation);
		print(file->lines, file->tokens); // УДАЛИТЬ
//		if (!ft_any_error(validation))
//		{
//			bytecode = convert_to_bytecode(file->tokens);
//			write_to_file(file, bytecode);
//		}
	}
	free_file(file);
}
