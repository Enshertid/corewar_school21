/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_instrs_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 15:21:15 by jgroleo           #+#    #+#             */
/*   Updated: 2020/05/27 14:17:54 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void				ft_check_ldi_lldi(t_check_args *ch, t_validation *v, int r)
{
	if (ch->arg[1][0] == ':' || ft_isdigit(ch->arg[1][0]) == 1
		|| ch->arg[2][0] != 'r')
	{
		v->error = 1;
		warning_add(ERROR, 3, "wrong types of argument in line №",
					ft_itoa_static(r + 1, 10), ".");
	}
}

void				ft_check_sti(t_check_args *ch, t_validation *val, int row)
{
	if (ch->arg[0][0] != 'r' || ch->arg[2][0] == ':' ||
		ft_isdigit(ch->arg[2][0]) == 1)
	{
		val->error = 1;
		warning_add(ERROR, 3, "wrong types of argument in line №",
					ft_itoa_static(row + 1, 10), ".");
	}
}

bool				useless_line(const char *line)
{
	while (*line && (*line == ' ' || *line == '\t'))
		++line;
	if (!*line || *line == COMMENT_CHAR || *line == ALT_COMMENT_CHAR)
		return (true);
	else
		return (false);
}

int					ft_check_closed_quote(char *str, t_validation *val)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '"')
		{
			if (i == (int)ft_strlen(str) - 1)
				return (1);
			else
			{
				val->error = 1;
				return (0);
			}
		}
		i++;
	}
	return (0);
}

t_check_args		*ft_malloc_checker(int *row, int *i)
{
	t_check_args	*checker;

	checker = (t_check_args*)malloc(sizeof(t_check_args));
	checker->arg = (char**)malloc(sizeof(char*) * 4);
	checker->arg[3] = NULL;
	*row = 0;
	*i = 0;
	return (checker);
}
