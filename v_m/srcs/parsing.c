/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enshertid <enshertid@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 19:21:59 by enshertid         #+#    #+#             */
/*   Updated: 2020/04/05 14:52:43 by enshertid        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "corewar.h"
#include "stdio.h"

void			parsing(t_pars *pars, t_players *players)
{
	if (pars->ac < 2)
		ft_error("Have no champions", NULL, 1);
	else if (pars->ac > (MAX_PLAYERS * 3) + 1)
		ft_error("To many arguments", NULL, 1);
	while (pars->i < pars->ac)
	{
		if (ft_strequ(pars->av[pars->i], "-n"))
			valid_flag(pars, players);
		else
			valid_name(pars, players);
		pars_champ(pars, players);
	}
	validate_id(players);
}
