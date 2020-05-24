/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_marks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 15:21:15 by jgroleo           #+#    #+#             */
/*   Updated: 2020/05/24 12:58:18 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void			ft_keep_fill_value(t_token *token, t_validation *v)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	if (ft_check_closed_quote(v->lines[*v->line_index], v) == 1)
	{
		tmp = token->value;
		tmp2 = ft_strndup(v->lines[*v->line_index],
				ft_strlen(v->lines[*v->line_index]) - 1);
		token->value = ft_strjoin(token->value, tmp2);
		free(tmp);
		free(tmp2);
	}
	else
	{
		tmp = token->value;
		tmp2 = ft_strndup(v->lines[*v->line_index],
				ft_strlen(v->lines[*v->line_index]));
		tmp3 = ft_strjoin(token->value, tmp2);
		token->value = ft_strjoin(tmp3, "\n");
		free(tmp);
		free(tmp2);
		free(tmp3);
	}
}

void			mark_name(const char **s, t_validation *v, t_token *t, bool *a)
{
	*a = true;
	t->type = NAME;
	v->name = 1;
	v->lines[*v->line_index]++;
	ft_scroll_line(s, v->lines, *v->line_index);
}

void			mark_c(const char **str, t_validation *v, t_token *t, bool *a)
{
	*a = true;
	t->type = COMMENT;
	v->comment = 1;
	v->lines[*v->line_index]++;
	ft_scroll_line(str, v->lines, *v->line_index);
}

void			ft_fill_value(t_token *token, t_validation *v)
{
	char	*tmp;

	if (ft_check_closed_quote(v->lines[*v->line_index], v) == 1)
		token->value = ft_strndup(v->lines[*v->line_index],
				ft_strlen(v->lines[*v->line_index]) - 1);
	else
	{
		tmp = ft_strjoin(v->lines[*v->line_index], "\n");
		token->value = ft_strndup(tmp, ft_strlen(v->lines[*v->line_index]) + 1);
		free(tmp);
	}
}

t_validation	*ft_create_val(void)
{
	t_validation	*val;

	val = (t_validation*)malloc(sizeof(*val));
	val->have_instructions = 0;
	val->name = 0;
	val->comment = 0;
	val->error = 0;
	val->dbl_c = 0;
	val->dbl_n = 0;
	val->no_n_start = 0;
	val->no_c_start = 0;
	val->no_newline_empty = 0;
	val->not_file = 0;
	return (val);
}
