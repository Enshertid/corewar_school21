/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_argument.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 13:03:53 by user              #+#    #+#             */
/*   Updated: 2020/05/29 22:37:48 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token_determinator.h"

static bool	if_register_skip(const char **lineptr)
{
	const char *line = *lineptr;

	if (line[0] == 'r' && ft_isdigit(line[1]))
	{
		line += 1;
		while (ft_isdigit(*line))
			line += 1;
		*lineptr = line;
		return (true);
	}
	else
		return (false);
}

static bool	if_offset_skip(const char **lineptr)
{
	const char *line = *lineptr;

	if (line[0] == '-' && ft_isdigit(line[1]))
		line += 1;
	while (ft_isdigit(*line))
		line += 1;
	if (line != *lineptr)
	{
		*lineptr = line;
		return (true);
	}
	else
		return (false);
}

static bool	if_label_skip(const char **lineptr)
{
	const char *line = *lineptr;

	if (*line != LABEL_CHAR)
		return (false);
	line += 1;
	while (*line && ft_strchr(LABEL_CHARS, *line))
		line += 1;
	if (*line != '\0' && *line != ' ' &&
		*line != '\t' && *line != SEPARATOR_CHAR)
		return (false);
	*lineptr = line;
	return (true);
}

bool		is_argument(const char **lineptr, t_token *token)
{
	const char	*line = *lineptr;
	bool		argument;

	argument = false;
	if (*line == DIRECT_CHAR)
		line += 1;
	argument = if_register_skip(&line);
	if (!argument)
		argument = if_offset_skip(&line);
	if (!argument)
		argument = if_label_skip(&line);
	if (argument)
	{
		token->type = ARGUMENT;
		token->value = ft_strndup(*lineptr, line - *lineptr);
		*lineptr = line;
	}
	return (argument);
}
