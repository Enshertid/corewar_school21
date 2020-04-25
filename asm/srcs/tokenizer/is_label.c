/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_label.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 12:59:07 by user              #+#    #+#             */
/*   Updated: 2020/04/25 13:51:51 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token_determinator.h"

bool	is_label(const char **lineptr, t_token *token)
{
	const char	*line = *lineptr;
	bool		name_exist;

	name_exist = false;
	while (*line && ft_strchr(LABEL_CHARS, *line))
	{
		name_exist = true;
		++line;
	}
	// while (*line == ' ' || *line == '\t')
	// 	++line;
	if (name_exist && *line == LABEL_CHAR)
	{
		token->type = LABEL;
		token->value = ft_strndup(*lineptr, line - *lineptr);
		*lineptr = line + 1;
		return (true);
	}
	else
		return (false);
}
