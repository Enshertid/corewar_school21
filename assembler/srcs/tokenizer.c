/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 23:45:40 by user              #+#    #+#             */
/*   Updated: 2020/06/02 23:45:40 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tokenizer.h"
#include "../includes/token_determinator.h"

static bool			useless_line(const char *line)
{
	while (*line && (*line == ' ' || *line == '\t'))
		++line;
	if (!*line || *line == COMMENT_CHAR || *line == ALT_COMMENT_CHAR)
		return (true);
	else
		return (false);
}

t_vector_token		line_to_tokens(const char *line, t_validation *validation)
{
	t_vector_token	tokens;
	t_token			token;

	tokens = vec_create(8, sizeof(t_token));
	if (useless_line(line) == true)
	{
		token.type = EMPTY;
		token.value = ft_strdup("");
		vec_pushback(&tokens, &token);
		return (tokens);
	}
	while (*line)
	{
		while (*line && (*line == ' ' || *line == '\t'))
			++line;
		if (*line == '\0' || *line == COMMENT_CHAR || *line == ALT_COMMENT_CHAR)
			break ;
		token = token_determinator(&line, validation);
		vec_pushback(&tokens, &token);
	}
	return (tokens);
}

t_vector_token		*tokenizer(t_vector_char *lines, t_validation *validation)
{
	const size_t	lines_count = vec_size(&lines);
	int				line_index;
	t_vector_token	*tokens;
	t_vector_token	tokens_line;

	validation->lines = lines;
	tokens = vec_create(lines_count, sizeof(t_vector_token));
	line_index = 0;
	validation->line_index = &line_index;
	validation->lines_count = lines_count;
	while (line_index < (int)lines_count)
	{
		tokens_line = line_to_tokens(lines[line_index], validation);
		vec_pushback(&tokens, &tokens_line);
		line_index += 1;
	}
	return (tokens);
}
