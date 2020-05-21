/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 15:53:09 by ediego            #+#    #+#             */
/*   Updated: 2020/05/19 20:40:41 by ediego           ###   ########.fr       */
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
// 	printf("LIFE: Id = %d Cycle: %d Car->pos = %d player = %d", car->id, vm->current_cycle, car->position, arg);
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
// 	if (type == player)
// 		check_register(vm, car);
	// car->position = get_new_pos(car->position, car->step);
// 	car->code = read_byte(vm, car->position) - 1;
// 	if (car->code >= 0 && car->code < OP_NUM)
// 		car->cycle_to_action = vm->operations.op_cycles[car->code];
// 	car->step = OP_BYTE;
// 	// printf(" REG = %d\n", car->registers[0]);
// 	printf("end: %d\n", car->position);
// }

static void 	check_player(t_vm *vm, t_car *car)
{
	int32_t player;

	player = read_four_bytes(vm, (car->position + 1) % MEM_SIZE) * -1;
	if (player > 0 && player <= vm->players.size)
		vm->players.arr[player - 1]->live = vm->current_cycle;
}

void 			op_live(t_vm *vm, t_car *car, t_arg *arg)
{
	(void)arg->first;
	if (vm->debug)		
		printf("Live(%d) Cycle: %d Pos = %d ", car->id, vm->current_cycle, car->position);
	vm->count_live++;
	car->last_live_cycle = 0;
	check_player(vm, car);
	car->position = (car->position + 5) % MEM_SIZE;
	if (vm->debug)
		printf("End pos: %d\n", car->position);
	car->step = OP_BYTE;
}
