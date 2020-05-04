#include "assembler.h"

static bool	useless_line(const char *line)
{
	while (*line && (*line == ' ' || *line == '\t'))
		++line;
	if (!*line || *line == COMMENT_CHAR)
		return (true);
	else
		return (false);
}

static void	read_file(t_file *file)
{
	char	*line;
	bool	final_newline_exist;

	file->lines = vec_create(80, sizeof(t_vector_char));
	while ((gnl(file->fd, &line, &final_newline_exist)) == GNL_OK)
	{
		if (useless_line(line))
			free(line);
		else
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
			free(file->tokens[token_line][i].value);
		}
		vec_destroy(&file->tokens[token_line]);
		token_line += 1;
	}
	vec_destroy(&file->tokens);
}

static void	error_handle(const t_file *file)
{
	if (file->status == FILE_NO_FINAL_NEWLINE)
		warning_add(ERROR, 3, "File \"", file->name,
							"\" haven\'t final newline");
	else if (file->status == FILE_EMPTY)
		warning_add(ERROR, 3, "File \"", file->name, "\" is empty");
}

static void print(t_vector_char *lines, t_vector_token *tokens)
{
	const char types[9][15] = {
		"LABEL",
		"INSTRUCTION",
		"ARGUMENT",
		"SEPARATOR",
		"NAME",
		"COMMENT",
		"UNKNOWN"
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
	file->status = FILE_OK;
	read_file(file);
	if (file->status != FILE_OK)
		error_handle(file);
	else
	{
		file->tokens = tokenizer(file->lines, validation);
		ft_check_labels(file->tokens, validation);
//		ft_check_instructions(file->lines, file->tokens, validation);
		print(file->lines, file->tokens);
		// tokens_analysis(file);
		// if (file->status == FILE_OK)
		// {
			// convert_to_bytecode(file);
			// write_to_file(file);
		// }

	}
	free_file(file);
}
