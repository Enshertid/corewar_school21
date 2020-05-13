/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 15:53:09 by ediego            #+#    #+#             */
/*   Updated: 2020/05/12 23:57:20 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

// static void	check_register(t_vm *vm, t_car *car)
// {
// 	int32_t arg;
	
// 	arg = read_four_bytes(vm, get_new_pos(car->position, car->step)) * -1;
// 	if (arg > 0 && arg < vm->players.size)
// 		vm->players.arr[arg - 1]->live = vm->current_cycle;
// 	printf("LIFE: Id = %d Cycle = %ld Car->pos = %d DIR = %d", car->id, vm->current_cycle, car->position, arg);
// }

// void 		op_live(t_vm *vm, t_car *car)
// {
// 	int8_t	type;
	
// 	printf("Life start = %d ", car->position);
// 	vm->count_live++;
// 	car->last_live_cycle = 0;
// 	type = determine_arg(read_byte(vm,
// 			get_new_pos(car->position, car->step)), 0);
// 	car->step += ARG_CHECK;
// 	if (type == DIR)
// 		check_register(vm, car);
	// car->position = get_new_pos(car->position, car->step);
// 	car->code = read_byte(vm, car->position) - 1;
// 	if (car->code >= 0 && car->code < OP_NUM)
// 		car->cycle_to_action = vm->operations.op_cycles[car->code];
// 	car->step = OP_BYTE;
// 	// printf(" REG = %d\n", car->registers[0]);
// 	printf("end: %d\n", car->position);
// }

static t_bool 	check_dir(t_vm *vm, t_car *car)
{
	int32_t dir;

	dir = read_four_bytes(vm, car->position + 1) * -1;
	if (dir > 0 && dir <= vm->players.size)
	{
		vm->players.arr[dir - 1]->live = vm->current_cycle;
		printf(" ID = %d ", dir);
		return (TRUE);
	}
	return (FALSE);
}

void 			op_live(t_vm *vm, t_car *car)
{
	printf("Live start = %d", car->position);
	vm->count_live++;
	car->last_live_cycle = 0;
	if (check_dir(vm, car))
		car->position += 5;
	else
		car->position += 1;
	car->code = read_byte(vm, car->position) - 1;
	if (car->code >= 0 && car->code < OP_NUM)
		car->cycle_to_action = vm->operations.op_cycles[car->code];
	printf("End: %d\n", car->position);
}
