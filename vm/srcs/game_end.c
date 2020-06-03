/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 20:52:49 by user              #+#    #+#             */
/*   Updated: 2020/06/03 20:52:50 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

bool			end_dump(t_vm *vm)
{
	t_car		*tmp;

	print_arena(vm->arena, vm->dump_size);
	tmp = vm->carriages;
	while (tmp)
		tmp = delete_from_begin(&vm->carriages, tmp);
	return (true);
}

bool			end_game(t_vm *vm, t_players *players)
{
	t_player	*winner;
	int8_t		id;

	id = vm->winner_id + '0';
	winner = players->arr[vm->winner_id - 1];
	write(1, "Contestant ", 11);
	write(1, &id, 1);
	write(1, ", \"", 3);
	id -= '0';
	write(1, winner->name, ft_strlen(winner->name));
	write(1, "\", has won !\n", 13);
	return (true);
}
