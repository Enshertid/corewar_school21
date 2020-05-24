/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_dump.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 14:19:18 by ediego            #+#    #+#             */
/*   Updated: 2020/05/24 15:59:25 by enshertid        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"

int64_t			ft_atotoi(const char *str)
{
	int64_t		res;
	short int	sign;

	while (ft_isspace(*str))
		++str;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		++str;
	}
	else if (*str == '+')
		++str;
	res = 0;
	while (ft_isdigit(*str))
		res = res * 10 + *str++ - '0';
	return (res * sign);
}

static void		check_dump(t_pars *pars)
{
	char		*str;

	if (!pars->dump_flag)
		pars->dump_flag = true;
	else if (pars->dump_flag)
		ft_error("dump flag is repeat", "valid dump", 2);
	if (!pars->av[++pars->i])
		ft_error("dump flag is incorrect", "valid dump", 2);
	str = pars->av[pars->i];
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error("dump flag is incorrect", "valid dump", 2);
		str++;
	}
}

bool			valid_dump(t_pars *pars, t_players *players)
{
	int64_t		long_dump_number;
	int32_t		dump_number;

	check_dump(pars);
	long_dump_number = ft_atotoi(pars->av[pars->i]);
	dump_number = long_dump_number;
	if ((int64_t)dump_number != long_dump_number)
		ft_error("overflow of int in dump flag, are you WSTYGG?",
												"valid dump", 2);
	players->dump_num = dump_number >= 0 ? dump_number : -1;
	++pars->i;
	return (true);
}
