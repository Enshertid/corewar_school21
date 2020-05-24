/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_instrs_three.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 15:21:15 by jgroleo           #+#    #+#             */
/*   Updated: 2020/05/24 12:58:18 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void		ft_last_t_not_arg(t_validation *val, int i)
{
	val->error = 1;
	warning_add(ERROR, 3, "last token in line №",
				ft_itoa_static(i + 1, 10), " is not argument.");
}

void		ft_parse_i(t_vector_token *t, int row, int *col, t_check_args *ch)
{
	ch->instr = t[row][*col].value;
	(*col)++;
	ch->i = -1;
	while (*col < vec_size(&t[row]))
	{
		if (t[row][*col].type == 2)
		{
			ch->i++;
			ch->arg[ch->i] = ft_strdup(t[row][*col].value);
		}
		(*col)++;
	}
}

void		ft_inc_i_row(int *i, int *row)
{
	(*row)++;
	(*i)++;
}

void		ft_check_instructions(t_vector_token *tokens, t_validation *val)
{
	int				row;
	int				col;
	int				i;
	t_check_args	*checker;

	checker = ft_malloc_checker(&row, &i);
	while (row < vec_size(&tokens))
	{
		col = 0;
		while (col < vec_size(&tokens[row]))
		{
			if (tokens[row][col].type == 1)
			{
				ft_parse_i(tokens, row, &col, checker);
				ft_check_arg(checker, val, row);
			}
			col++;
		}
		col -= 2;
		if (ft_check_last_arg(tokens, row, col) == 1)
			ft_last_t_not_arg(val, i);
		ft_inc_i_row(&i, &row);
	}
	free(checker->arg);
	free(checker);
}

void		ft_synt_error(t_validation *val, int row)
{
	val->error = 1;
	warning_add(ERROR, 3, "syntax error in line №",
				ft_itoa_static(row + 1, 10), ".");
}
