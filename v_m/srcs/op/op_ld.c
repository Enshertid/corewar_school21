/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 15:57:24 by ediego            #+#    #+#             */
/*   Updated: 2020/05/13 12:56:18 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

void 		op_ld(t_vm *vm, t_car *car)
{
	int32_t value;
	int8_t reg;
	int ind;
	int8_t args;

	printf("LD(%d): Cycle = %ld  POS = %d ", car->id, vm->current_cycle, car->position);
	args = vm->arena[(car->position + 1) % MEM_SIZE];
	if (check_arg(args) == DIR_CODE && check_arg(args << 2) == REG_CODE)
	{
		value = read_four_bytes(vm, car->position + 2);
		reg = vm->arena[(car->position + 6) % MEM_SIZE] - 1;
		printf("DIR = %d REG = %d ", value, reg);
		set_reg(car, reg, value);
	}
	else if (check_arg(args) == IND_CODE && check_arg(args << 2) == REG_CODE)
	{
		ind = car->position + (read_two_bytes(vm, car->position + 2) % IDX_MOD);
		value = read_four_bytes(vm, ind);
		reg = vm->arena[(car->position + 4) % MEM_SIZE];
		printf("IND = %d  REG = %d ", ind, reg);
		set_reg(car, reg, value);
	}
	car->position += get_arg_step(args, 2, DIR_SIZE);
	car->code = vm->arena[car->position] - 1;
	if (car->code >= 0 && car->code < 16)
		car->cycle_to_action = vm->operations.op_cycles[car->code];
	printf(" carry = %d END pos = %d\n", car->carry, car->position);
}
