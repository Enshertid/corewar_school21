/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_instrs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 15:21:15 by jgroleo           #+#    #+#             */
/*   Updated: 2020/05/24 12:58:18 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	ft_check_aff(t_check_args *checker, t_validation *val, int row)
{
	if (checker->arg[0][0] != 'r')
	{
		val->error = 1;
		warning_add(ERROR, 3, "wrong types of argument in line №",
					ft_itoa_static(row + val->extr + 1, 10), ".");
	}
}

void	ft_check_zjmp_l_f_lf(t_check_args *checker, t_validation *val, int row)
{
	if (checker->arg[0][0] != '%')
	{
		val->error = 1;
		warning_add(ERROR, 3, "wrong types of argument in line №",
					ft_itoa_static(row + val->extr + 1, 10), ".");
	}
}

void	ft_check_st(t_check_args *checker, t_validation *val, int row)
{
	if (checker->arg[0][0] != 'r' || checker->arg[1][0] == '%')
	{
		val->error = 1;
		warning_add(ERROR, 3, "wrong types of argument in line №",
					ft_itoa_static(row + val->extr + 1, 10), ".");
	}
}

void	ft_check_add_sub(t_check_args *checker, t_validation *val, int row)
{
	if (checker->arg[0][0] != 'r' || checker->arg[1][0] != 'r' ||
		checker->arg[2][0] != 'r')
	{
		val->error = 1;
		warning_add(ERROR, 3, "wrong types of argument in line №",
					ft_itoa_static(row + val->extr + 1, 10), ".");
	}
}

void	ft_check_and_or_xor(t_check_args *checker, t_validation *val, int row)
{
	if (checker->arg[2][0] != 'r')
	{
		val->error = 1;
		warning_add(ERROR, 3, "wrong types of argument in line №",
					ft_itoa_static(row + val->extr + 1, 10), ".");
	}
}
