/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_separator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 13:43:14 by user              #+#    #+#             */
/*   Updated: 2020/05/25 17:16:34 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/token_determinator.h"

bool	is_separator(const char **lineptr, t_token *token)
{
	if (**lineptr == SEPARATOR_CHAR)
	{
		token->type = SEPARATOR;
		token->value = ft_strndup(*lineptr, 1);
		*lineptr += 1;
		return (true);
	}
	else
		return (false);
}
