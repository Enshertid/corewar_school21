/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_dump.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 20:55:23 by user              #+#    #+#             */
/*   Updated: 2020/06/03 20:55:23 by user             ###   ########.fr       */
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
	if (ft_strequ(pars->av[(pars->i) - 1], "-d"))
		players->dump_size = 64;
	else
		players->dump_size = 32;
	players->dump_num = dump_number >= 0 ? dump_number : -1;
	++pars->i;
	return (true);
}
