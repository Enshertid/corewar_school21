/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 15:57:24 by ediego            #+#    #+#             */
/*   Updated: 2020/05/15 22:15:32 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

void 		op_ld(t_vm *vm, t_car *car)
{
	int32_t value;
	int8_t reg;
	int pos;
	int8_t args;

	printf("LD(%d): Cycle = %ld  POS = %d ", car->id, vm->current_cycle, car->position);
	args = vm->arena[(car->position + 1) % MEM_SIZE];
	if (check_arg(args) == DIR_CODE && check_arg(args << 2) == REG_CODE)
	{
		value = read_four_bytes(vm, car->position + 2);
		reg = vm->arena[(car->position + 6) % MEM_SIZE];
		if (reg > 0 && reg <= REG_NUMBER)
			set_reg(car, reg, value, 1);
	}
	else if (check_arg(args) == IND_CODE && check_arg(args << 2) == REG_CODE)
	{
		pos = car->position + get_pos(read_two_bytes(vm, (car->position + 2) % MEM_SIZE));
		// pos = car->position + (read_two_bytes(vm, car->position + 2) % IDX_MOD);
		value = read_four_bytes(vm, pos);
		reg = vm->arena[(car->position + 4) % MEM_SIZE];
		if (reg > 0 && reg <= REG_NUMBER)
			set_reg(car, reg, value, 1);
	}
	car->position += get_arg_step(args, 2, DIR_SIZE);
	car->code = vm->arena[car->position] - 1;
	if (car->code >= 0 && car->code < OP_NUM)
		car->cycle_to_action = vm->operations.op_cycles[car->code];
	car->step = OP_BYTE;
	printf(" carry = %d END pos = %d\n", car->carry, car->position);
}
