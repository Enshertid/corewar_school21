/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 15:53:09 by ediego            #+#    #+#             */
/*   Updated: 2020/05/21 13:30:25 by ediego           ###   ########.fr       */
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
	// if (vm->debug)		
	// 	printf("Live(%d) Cycle = %d Pos = %d ", car->id, vm->current_cycle,
				// car->position);
	vm->count_live++;
	car->last_live_cycle = 0;
	check_player(vm, car);
	car->position = (car->position + 5) % MEM_SIZE;
	// if (vm->debug)
	// 	printf("End pos: %d\n", car->position);
	car->step = OP_BYTE;
}
