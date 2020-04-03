/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_champ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enshertid <enshertid@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 19:31:10 by enshertid         #+#    #+#             */
/*   Updated: 2020/04/03 20:11:04 by enshertid        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "op.h"

void			pars_champ(t_pars *pars, t_players *players, int *i)
{
	if (players->iter >= MAX_PLAYERS)
		ft_error("too many champions", "validate id", 2);
	if (!players->arr[players->iter])
		players->arr[players->iter] = ft_calloc(1, sizeof(t_player));
	players->arr[players->iter]->id = players->iter + 1;
	players->arr[players->iter]->flag_of_n = FALSE;
	players->arr[players->iter]->name = pars->av[*i];
	pars->fd = open(pars->av[*i], O_RDONLY);
	players->iter++;
	(*i)++;
}
