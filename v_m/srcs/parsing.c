/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enshertid <enshertid@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 19:21:59 by enshertid         #+#    #+#             */
/*   Updated: 2020/04/03 20:08:28 by enshertid        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "corewar.h"
#include "stdio.h"

void			pars_id(t_pars *pars, t_players *players, int *i)
{
	size_t	iter;
	int		id;

	iter = 0;
	(*i)++;
	while (pars->av[*i][iter])
	{
		if (!ft_isdigit(pars->av[*i][iter]))
			ft_error("id is incorrect", "pars_id", 2);
		iter++;
	}
	id = ft_atoi(pars->av[(*i)++]);
	if ((id > MAX_PLAYERS) || (id < 1))
		ft_error ("id is incorrect", "pars id", 2);
	pars_champ(pars, players, i);
	players->arr[players->iter - 1]->flag_of_n = TRUE;
	players->arr[players->iter - 1]->id = id;
}

void			parsing(t_pars *pars, t_players *players)
{
	int				i;

	i = 1;
	if (pars->ac < 2)
		ft_error("Have no champions", NULL, 1);
	else if (pars->ac > (MAX_PLAYERS * 3) + 1)
		ft_error("To many arguments", NULL, 1);
	while (i < pars->ac)
	{
		if (ft_strequ(pars->av[i], "-n"))
			pars_id(pars, players, &i);
		else
			pars_champ(pars, players, &i);
	}
	validate_id(players);
}
