#include "assembler.h"

static t_bool	useless_line(const char *line)
{
	while (*line && (*line == ' ' || *line == '\t'))
		++line;
	if (!*line || *line == COMMENT_CHAR)
		return (TRUE);
	else
		return (FALSE);
}

static void		read_file(t_file *file)
{
	char		*line;
	t_bool		final_newline;

	file->lines = vec_create(80, sizeof(t_vector_char));
	while ((gnl(file->fd, &line, &final_newline)) == GNL_OK)
	{
		if (useless_line(line))
			free(line);
		else
			vec_pushback(&file->lines, &line);
	}
	if (vec_size(&file->lines) == 0)
		file->status = FILE_EMPTY;
	else if (final_newline == FALSE)
		file->status = FILE_NO_FINAL_NEWLINE;
}

static void		free_file(t_file *file)
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
			if (file->tokens[token_line][i].type != INSTRUCTION)
				free(file->tokens[token_line][i].value);
		}
		vec_destroy(&file->tokens[token_line]);
		token_line += 1;
	}
	vec_destroy(&file->tokens);
}

void			assembly(t_file *file)
{
	file->status = FILE_OK;
	read_file(file);
	if (file->status == FILE_NO_FINAL_NEWLINE)
		warning_add(ERROR, 3, "File \"", file->name,
							"\" haven\'t final newline");
	else if (file->status == FILE_EMPTY)
		warning_add(ERROR, 3, "File \"", file->name, "\" is empty");
	else
	{
		file->tokens = tokenizer(file->lines);
		// tokens_analysis(file);
		// if (file->status == FILE_OK)
		// {
			// convert_to_bytecode(file);
			// write_to_file(file);
		// }

	}
	free_file(file);
}
