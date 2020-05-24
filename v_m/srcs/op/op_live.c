/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 15:53:09 by ediego            #+#    #+#             */
/*   Updated: 2020/05/23 23:12:06 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

static void 	check_player(t_vm *vm, t_car *car)
{
	int32_t player;

	player = read_four_bytes(vm, (car->position + 1) % MEM_SIZE) * - 1;
	if (player > 0 && player <= vm->players.size)
		vm->winner_id = player;
}

void 			op_live(t_vm *vm, t_car *car, t_arg *arg)
{
	(void)arg->first;
	vm->count_live++;
	car->last_live_cycle = 0;
	check_player(vm, car);
	car->position = (car->position + 5) % MEM_SIZE;
	car->step = OP_BYTE;
}
