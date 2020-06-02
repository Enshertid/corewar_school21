/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fills.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enshertid <enshertid@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 15:21:15 by jgroleo           #+#    #+#             */
/*   Updated: 2020/06/03 01:13:20 by enshertid        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int					ft_keep_fill_value(t_token *token, t_validation *v)
{
	char	*tmp;
	char	*tmp2;

	v->extr++;
	if (ft_check_closed_quote(v->lines[*v->line_index], v) == 1)
	{
		tmp2 = token->value;
		tmp = ft_strndup(v->lines[*v->line_index],
				ft_find_last_quote(v->lines[*v->line_index]));
		token->value = ft_strjoin(tmp2, tmp);
		free(tmp);
		free(tmp2);
		return (1);
	}
	else
	{
		tmp = ft_strndup(v->lines[*v->line_index],
				ft_strlen(v->lines[*v->line_index]));
		tmp2 = ft_strjoin(token->value, tmp);
		free(token->value);
		token->value = ft_strjoin(tmp2, "\n");
		free(tmp);
		free(tmp2);
		return (0);
	}
}

int					ft_fill_value(t_token *t, t_validation *v, const char **str)
{
	char	*tmp;

	if (ft_check_closed_quote(v->lines[*v->line_index], v) == 1)
	{
		t->value = ft_strndup(v->lines[*v->line_index],
				ft_find_last_quote(v->lines[*v->line_index]));
		ft_scroll_line((char**)str, v->lines, *v->line_index);
		return (1);
	}
	else
	{
		if (v->trash_aft_name == 1)
			return (0);
		tmp = ft_strjoin(v->lines[*v->line_index], "\n");
		t->value = ft_strndup(tmp, ft_strlen(v->lines[*v->line_index]) + 1);
		free(tmp);
		ft_scroll_line((char**)str, v->lines, *v->line_index);
		return (0);
	}
}

t_check_args		*ft_malloc_checker(int *row, int *i)
{
	t_check_args	*checker;

	checker = (t_check_args*)malloc(sizeof(t_check_args));
	checker->arg = (char**)malloc(sizeof(char*) * 4);
	checker->arg[3] = NULL;
	checker->col = 0;
	*row = 0;
	*i = 0;
	return (checker);
}

void				ft_parse_i_and_check_arg(t_vector_token *t, t_validation *v,
		t_check_args *ch, int r)
{
	ft_parse_i(t, r, ch);
	ft_check_arg(ch, v, r);
}
