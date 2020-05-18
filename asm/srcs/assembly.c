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
		free(file->lines[line]);
		line += 1;
	}
	vec_destroy(&file->lines);
	token_line = 0;
	while (token_line < tokens_amount)
	{
		for (size_t i = 0; i < vec_size(&file->tokens[token_line]); ++i) {
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
	const char types[7][15] = {
		"LABEL",
		"INSTRUCTION",
		"ARGUMENT",
		"SEPARATOR",
		"UNKNOWN"
	};

	for (size_t row = 0; row < vec_size(&tokens); ++row)
	{
		//printf("Line %zu: %s\n", row, lines[row]);
		//printf("Tokens:\n");
		for (size_t col = 0; col < vec_size(&tokens[row]); ++col) {
			//printf("\tType: %s, value: \"%s\"\n", types[tokens[row][col].type],
											tokens[row][col].value);
		}
		//printf("\n");
	}
}

void		assembly(t_file *file)
{
	file->status = FILE_OK;
	read_file(file);
	if (file->status != FILE_OK)
		error_handle(file);
	else
	{
		file->tokens = tokenizer(file->lines);
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
