//
// Created by Daniil&Ekaterina Naumenko on 11/05/2020.
//

#include "pars.h"

static int64_t		ft_atotoi(const char *str)
{
	int64_t			res;
	short int		sign;
	
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

void			valid_dump(t_pars *pars, t_players *players)
{
	char		*str;
	int64_t		long_dump_number;
	int32_t 	dump_number;
	
	str = pars->av[pars->i];
	while(*str)
	{
		if (!ft_isdigit(*str))
			ft_error("dump flag is incorrect", "valid dump", 2);
		str++;
	}
	long_dump_number = ft_atotoi(pars->av[pars->i]);
	dump_number = long_dump_number;
	if ((int64_t)dump_number != long_dump_number)
		ft_error("overflow of int in dump flag, are you WSTYGG?",
				 "valid dump", 2);
	if (dump_number > 0)
	{
		players->dump_flag = TRUE;
		players->dump_num = dump_number;
	}
}