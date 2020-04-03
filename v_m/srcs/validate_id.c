/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enshertid <enshertid@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 18:44:19 by enshertid         #+#    #+#             */
/*   Updated: 2020/04/03 19:21:37 by enshertid        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdio.h>
#include "op.h"

void			sort_id(t_players *players, size_t i, size_t j)
{
	t_player	*tmp;
	t_player	**ar;

	ar = ft_calloc(MAX_PLAYERS, sizeof(t_player*));
	while (++i < players->iter)
		if (!players->arr[i]->flag_of_n)
			ar[j++] = players->arr[i];
	i = -1;
	while (++i < players->iter)
		while (players->arr[i]->flag_of_n && i != players->arr[i]->id - 1)
		{
			tmp = players->arr[players->arr[i]->id - 1];;
			players->arr[players->arr[i]->id - 1] = players->arr[i];
			players->arr[i] = tmp;
		}
	i = -1;
	j = 0;
	while (++i < players->iter)
	{
		if (!players->arr[i]->flag_of_n)
			players->arr[i] = ar[j++];
		players->arr[i]->id = i + 1;
	}
	i = -1;
	while (++i < players->iter)
		printf("name : %s || id ==> %zu\n", players->arr[i]->name, players->arr[i]->id);
	free(ar);
}

void			validate_id(t_players *players)
{
	size_t		i;
	size_t		j;

	i = -1;
	while (++i < players->iter)
	{
		if (players->arr[i]->id > players->iter)
			ft_error ("too large id", "validate_id", 2);
		j = i;
		while (++j < players->iter)
			if (players->arr[i]->flag_of_n && players->arr[j]->
			flag_of_n && players->arr[i]->id == players->arr[j]->id)
				ft_error("id can't repeat", "validate_id", 2);
	}
	i = -1;
	j = 0;
	sort_id(players, i, j);
}
