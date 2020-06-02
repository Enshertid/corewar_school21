/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_marks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enshertid <enshertid@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 15:21:15 by jgroleo           #+#    #+#             */
/*   Updated: 2020/06/03 01:07:02 by enshertid        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void			mark_name(char **s, t_validation *v, t_token *t, bool *a)
{
	*a = true;
	t->type = NAME;
	v->name = 1;
	v->lines[*v->line_index]++;
	ft_scroll_line(s, v->lines, *v->line_index);
}

void			mark_c(char **str, t_validation *v, t_token *t, bool *a)
{
	*a = true;
	t->type = COMMENT;
	v->comment = 1;
	v->lines[*v->line_index]++;
	ft_scroll_line(str, v->lines, *v->line_index);
}

int				ft_find_last_quote(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '"')
			return (i);
		i++;
	}
	return (0);
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
	val->trash_aft_name = 0;
	val->extr = 0;
	val->lines_count = 0;
	return (val);
}
