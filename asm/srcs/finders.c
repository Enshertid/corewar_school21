/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 19:17:05 by user              #+#    #+#             */
/*   Updated: 2020/05/27 19:18:17 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

const char	*find_name(t_vector_token *tokens)
{
	const int	lines = vec_size(&tokens);
	int			line;

	line = 0;
	while (line < lines)
	{
		if (tokens[line][0].type == NAME)
			return (tokens[line][0].value);
		line += 1;
	}
	return (NULL);
}

const char	*find_comment(t_vector_token *tokens)
{
	const int	lines = vec_size(&tokens);
	int			line;

	line = 0;
	while (line < lines)
	{
		if (tokens[line][0].type == COMMENT)
			return (tokens[line][0].value);
		line += 1;
	}
	return (NULL);
}
