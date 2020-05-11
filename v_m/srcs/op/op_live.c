/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 15:53:09 by ediego            #+#    #+#             */
/*   Updated: 2020/05/11 22:06:22 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

void 		op_live(t_vm *vm, t_car *car)
{
	int32_t arg;
	
	arg = get_4byte(vm, get_new_pos(car->position, OP_BYTE));
	printf("LIFE: Id = %d Cycle = %ld Car->pos = %d DIR = %d", car->id, vm->current_cycle, car->position, arg);
	vm->count_live++;
	car->last_live_cycle = 0;
	car->position = get_new_pos(car->position, 5);
	if (arg <= -1 && arg >= -(vm->players->size))
	{
		arg *= -1;
		arg--;
		vm->players->arr[arg]->live = vm->current_cycle;
		vm->last_live_id = arg;
	}
	car->code = vm->arena[car->position] - 1;
	if (car->code >= 0 && car->code < 16)
		car->cycle_to_action = vm->operations.op_cycles[car->code];
	printf(" In end: Car->pos = %d\n", car->position);
}
