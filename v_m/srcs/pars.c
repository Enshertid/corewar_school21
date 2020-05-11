/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 19:21:59 by enshertid         #+#    #+#             */
/*   Updated: 2020/05/10 17:42:48 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"

void			parsing(t_players *players, int ac, char **av)
{
	t_pars		pars;
	
	ft_memset(&pars, 0, sizeof(t_pars));
	pars.ac = ac;
	pars.av = av;
	pars.i = 1;
	if (pars.ac < 2)
		ft_error("Have no champions", NULL, 1);
	else if (pars.ac > (MAX_PLAYERS * 3) + 1)
		ft_error("To many arguments", NULL, 1);
	while (pars.i < pars.ac)
	{
		if (ft_strequ(pars.av[pars.i], "-n"))
			valid_flag(&pars, players);
		else
			valid_name(&pars, players);
		pars_champ(&pars, players);
	}
	validate_id(players);
}
