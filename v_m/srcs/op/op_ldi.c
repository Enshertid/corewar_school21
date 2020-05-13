/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 18:40:20 by ediego            #+#    #+#             */
/*   Updated: 2020/05/13 15:05:09 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

void 		op_ldi(t_vm *vm, t_car *car)
{
	int8_t args;
	int32_t addr;
	int32_t arg1;
	int32_t value;

	car->step = 2;
	printf("LDI(%d): Cycle = %ld  POS = %d ", car->id, vm->current_cycle, car->position);
	args = vm->arena[(car->position + 1) % MEM_SIZE];
	arg1 = get_arg_n(vm, car, args);
	addr = car->position + (arg1 + get_arg_n(vm, car, args << 2) % IDX_MOD);
	value = read_four_bytes(vm, addr);
	set_reg(car, vm->arena[(car->position + car->step) % MEM_SIZE], value);
	car->code = vm->arena[car->position] - 1;
	if (car->code >= 0 && car->code < 16)
		car->cycle_to_action = vm->operations.op_cycles[car->code];
	car->position += get_arg_step(args, 2, DIR_SIZE / 2);
	printf(" carry = %d END pos = %d\n", car->carry, car->position);
}
