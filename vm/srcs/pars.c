/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 20:55:14 by user              #+#    #+#             */
/*   Updated: 2020/06/03 20:55:15 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"

static bool			valid_aff(t_pars *pars, t_players *players)
{
	pars->i++;
	if (players->aff == false)
		players->aff = true;
	else
		ft_error("second aff flag", "valid aff", 2);
	return (true);
}

static void			finish_players(t_players *players, int8_t new_size)
{
	t_player		**new_array;

	players->iter = 0;
	players->size = new_size;
	if (!(new_array = ft_calloc(new_size, sizeof(t_player*))))
		ft_error("error in malloc", "finish_players", 3);
	else
	{
		while (players->iter != new_size)
		{
			new_array[players->iter] = players->arr[players->iter];
			players->iter++;
		}
		free(players->arr);
		players->arr = new_array;
	}
}

static void			init_pars(t_pars *pars, int ac, char **av)
{
	ft_memset(pars, 0, sizeof(t_pars));
	pars->ac = ac;
	pars->av = av;
	pars->i = 1;
}

void				parsing(t_players *players, int ac, char **av)
{
	t_pars			pars;

	init_pars(&pars, ac, av);
	if (pars.ac < 2)
		ft_error("Have no champions", NULL, 1);
	else if (pars.ac > MAX_PLAYERS * 3 + DUMP)
		ft_error("To many arguments", NULL, 1);
	while (pars.i < pars.ac)
	{
		if ((ft_strequ(pars.av[pars.i], "-dump") ||
		ft_strequ(pars.av[pars.i], "-d")) && valid_dump(&pars, players))
			continue ;
		if (ft_strequ(pars.av[pars.i], "-a") && valid_aff(&pars, players))
			continue ;
		if (ft_strequ(pars.av[pars.i], "-n"))
			valid_flag(&pars, players);
		else
			valid_name(&pars, players);
		pars_champ(&pars, players);
	}
	if (players->iter == 0)
		ft_error("Have no champions", NULL, 2);
	validate_id(players);
	if (players->iter != players->size)
		finish_players(players, players->iter);
}
