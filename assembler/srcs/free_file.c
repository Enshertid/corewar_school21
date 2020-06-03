/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 14:36:29 by user              #+#    #+#             */
/*   Updated: 2020/05/27 14:45:57 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static void	destroy_lines(t_vector_char *copy, t_vector_char *lines)
{
	const int	lines_count = vec_size(&copy);
	int			line;

	line = 0;
	while (line < lines_count)
	{
		free(copy[line]);
		line += 1;
	}
	vec_destroy(&copy);
	vec_destroy(&lines);
}

static void	destroy_bytecode(t_vector_char *bytecode)
{
	const int	lines_count = vec_size(&bytecode);
	int			line;

	line = 0;
	while (line < lines_count)
	{
		vec_destroy(&bytecode[line]);
		line += 1;
	}
	vec_destroy(&bytecode);
}

static void	destroy_tokens(t_vector_token *tokens)
{
	const int	lines_count = vec_size(&tokens);
	int			line;
	int			tokens_count;
	int			token;

	line = 0;
	while (line < lines_count)
	{
		tokens_count = vec_size(&tokens[line]);
		token = 0;
		while (token < tokens_count)
		{
			free(tokens[line][token].value);
			token += 1;
		}
		vec_destroy(&tokens[line]);
		line += 1;
	}
	vec_destroy(&tokens);
}

void		free_file(t_file *file)
{
	if (file->copy)
		destroy_lines(file->copy, file->lines);
	if (file->bytecode)
		destroy_bytecode(file->bytecode);
	if (file->tokens)
		destroy_tokens(file->tokens);
}
