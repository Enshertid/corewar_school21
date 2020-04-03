/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enshertid <enshertid@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 14:12:43 by enshertid         #+#    #+#             */
/*   Updated: 2020/04/03 19:05:20 by enshertid        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "players.h"
#include "op.h"

void			init_players(t_players *players)
{
		players->arr = ft_calloc(MAX_PLAYERS, sizeof(t_player*));
		players->size = MAX_PLAYERS;
}
