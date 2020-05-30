/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 15:21:15 by jgroleo           #+#    #+#             */
/*   Updated: 2020/05/24 12:58:18 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	ft_check_one_arg(t_check_args *checker, t_validation *val, int row)
{
	if (ft_strcmp(checker->instr, "aff") == 0)
		ft_check_aff(checker, val, row);
	else if (ft_strcmp(checker->instr, "zjmp") == 0 ||
	ft_strcmp(checker->instr, "live") == 0 ||
	ft_strcmp(checker->instr, "fork") == 0 ||
	ft_strcmp(checker->instr, "lfork") == 0)
		ft_check_zjmp_l_f_lf(checker, val, row);
	else
	{
		val->error = 1;
		warning_add(ERROR, 3, "wrong types of argument in line №",
					ft_itoa_static(row + val->extr + 1, 10), ".");
	}
}

void	ft_check_two_arg(t_check_args *checker, t_validation *val, int row)
{
	if (ft_strcmp(checker->instr, "st") == 0)
		ft_check_st(checker, val, row);
	else if (ft_strcmp(checker->instr, "ld") == 0 ||
	ft_strcmp(checker->instr, "lld") == 0)
	{
		if (checker->arg[0][0] == 'r' || checker->arg[1][0] != 'r')
		{
			val->error = 1;
			warning_add(ERROR, 3, "wrong types of argument in line №",
						ft_itoa_static(row + val->extr + 1, 10), ".");
		}
	}
	else
	{
		val->error = 1;
		warning_add(ERROR, 3, "wrong types of argument in line №",
					ft_itoa_static(row + val->extr + 1, 10), ".");
	}
}

void	ft_check_three_arg(t_check_args *checker, t_validation *val, int row)
{
	if (ft_strcmp(checker->instr, "add") == 0 ||
		ft_strcmp(checker->instr, "sub") == 0)
		ft_check_add_sub(checker, val, row);
	else if (ft_strcmp(checker->instr, "and") == 0 ||
	ft_strcmp(checker->instr, "or") == 0 ||
	ft_strcmp(checker->instr, "xor") == 0)
		ft_check_and_or_xor(checker, val, row);
	else if (ft_strcmp(checker->instr, "ldi") == 0 ||
	ft_strcmp(checker->instr, "lldi") == 0)
		ft_check_ldi_lldi(checker, val, row);
	else if (ft_strcmp(checker->instr, "sti") == 0)
		ft_check_sti(checker, val, row);
	else
	{
		val->error = 1;
		warning_add(ERROR, 3, "wrong types of argument in line №",
					ft_itoa_static(row + val->extr + 1, 10), ".");
	}
}

void	ft_check_arg(t_check_args *checker, t_validation *val, int row)
{
	int		i;

	if (checker->i == -1)
	{
		val->error = 1;
		warning_add(ERROR, 3, "no arguments in line №",
					ft_itoa_static(row + val->extr + 1, 10), ".");
		return ;
	}
	i = checker->i;
	if (i == 0)
		ft_check_one_arg(checker, val, row);
	else if (i == 1)
		ft_check_two_arg(checker, val, row);
	else if (i == 2)
		ft_check_three_arg(checker, val, row);
	else
		val->error = 1;
	while (i > -1)
	{
		free(checker->arg[i]);
		i--;
	}
}

int		ft_check_last_arg(t_vector_token *t, int row, int col)
{
	if (t[row][col].type != 2 && t[row][0].type != 4 &&
		t[row][0].type != 5 && col != -1 && t[row][col].type != 6)
		return (1);
	else
		return (0);
}
