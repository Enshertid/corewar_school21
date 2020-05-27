/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_com.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 15:21:15 by jgroleo           #+#    #+#             */
/*   Updated: 2020/05/27 13:56:03 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int		ft_check_com_string(t_validation *v)
{
	while (*(v->lines[*v->line_index]) == ' ' ||
			*(v->lines[*v->line_index]) == '\t')
		v->lines[*v->line_index]++;
	if (ft_strncmp(v->lines[*v->line_index], COMMENT_CMD_STRING,
			ft_strlen(COMMENT_CMD_STRING)) == 0)
		return (1);
	else
		return (0);
}

int		ft_fill_com(const char **str, t_validation *v, t_token *t, bool *a)
{
	if (t->value == NULL)
		ft_fill_value(t, v);
	if (*v->lines[*v->line_index] == '"')
	{
		if (ft_strlen(v->lines[*v->line_index] + 1) > 0)
		{
			v->lines[*v->line_index]++;
			ft_scroll_line(str, v->lines, *v->line_index);
			return (1);
		}
		mark_c(str, v, t, a);
		return (1);
	}
	return (0);
}

int		ft_dbl_c(const char **str, t_validation *v)
{
	if (v->comment == 1)
	{
		warning_add(ERROR, 3, "Extra comment in line №",
					ft_itoa_static(*v->line_index + 1, 10), ".");
		ft_scroll_line(str, v->lines, *v->line_index);
		v->dbl_c = 1;
		return (1);
	}
	return (0);
}

int		ft_parse_com(const char **str, t_validation *v, t_token *t, bool *a)
{
	if (t->value != NULL)
		ft_keep_fill_value(t, v);
	if (ft_strlen(v->lines[*v->line_index]) == 0)
		t->value = ft_strndup("\n", 1);
	while (*v->lines[*v->line_index])
	{
		if (ft_fill_com(str, v, t, a) == 1)
			return (1);
		v->lines[*v->line_index]++;
	}
	return (0);
}

bool	is_comment(const char **str, t_token *token, t_validation *v)
{
	bool		argument;

	argument = false;
	if (ft_check_com_string(v) == 1)
	{
		if (ft_dbl_c(str, v) == 1)
			return (argument);
		token->value = 0;
		v->lines[*v->line_index] += ft_strlen(COMMENT_CMD_STRING);
		while (*v->lines[*v->line_index] == ' ' ||
		*v->lines[*v->line_index] == '\t')
			v->lines[*v->line_index]++;
		if (*v->lines[*v->line_index] == '"')
		{
			v->lines[*v->line_index]++;
			while (v->lines[*v->line_index])
			{
				if (ft_parse_com(str, v, token, &argument) == 1)
					return (argument);
				*v->line_index += 1;
			}
		}
		ft_scroll_line(str, v->lines, *v->line_index);
	}
	return (argument);
}
