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

static void	check_register(t_vm *vm, t_car *car)
{
	int32_t arg;
	
	arg = get_4byte(vm, get_new_pos(car->position, car->step)) * -1;
	if (arg > 0 && arg < vm->players.size)
		vm->players.arr[arg - 1]->live = vm->current_cycle;
	printf("LIFE: Id = %d Cycle = %ld Car->pos = %d DIR = %d", car->id, vm->current_cycle, car->position, arg);
}

void 		op_live(t_vm *vm, t_car *car)
{
	int8_t	type;
	
	printf(" In start: Car->pos = %d\n", car->position);
	vm->count_live++;
	car->last_live_cycle = 0;
	type = determine_arg(read_byte(vm,
			get_new_pos(car->position, car->step)), 0);
	car->step += ARG_CHECK;
	if (type == DIR)
		check_register(vm, car);
	car->position = get_new_pos(car->position, car->step);
	car->code = read_byte(vm, car->position) - 1;
	if (car->code >= 0 && car->code < OP_NUM)
		car->cycle_to_action = vm->operations.op_cycles[car->code];
	car->step = OP_BYTE;
	printf(" In end: Car->pos = %d\n", car->position);
}
