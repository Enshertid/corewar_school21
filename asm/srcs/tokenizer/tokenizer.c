#include "tokenizer.h"
#include "token_determinator.h"

t_vector_token		line_to_tokens(const char *line)
{
	t_vector_token	tokens;
	t_token			token;

	tokens = vec_create(8, sizeof(t_token));
	while (*line)
	{
		while (*line && (*line == ' ' || *line == '\t'))
			++line;
		if (*line == COMMENT_CHAR)
			break ;
		token = token_determinator(&line);
		vec_pushback(&tokens, &token);
	}
	return (tokens);
}

t_vector_token		*tokenizer(t_vector_char *lines)
{
	const size_t	lines_count = vec_size(&lines);
	size_t			line_index;
	t_vector_token	*tokens;
	t_vector_token	tokens_line;

	tokens = vec_create(lines_count, sizeof(t_vector_token));
	line_index = 0;
	while (line_index < lines_count)
	{
		tokens_line = line_to_tokens(lines[line_index]);
		vec_pushback(&tokens, &tokens_line);
		line_index += 1;
	}
	return (tokens);
}
