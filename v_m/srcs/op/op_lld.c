/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 18:45:07 by ediego            #+#    #+#             */
/*   Updated: 2020/05/17 16:25:51 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

void 		op_lld(t_vm *vm, t_car *car)
{
	int32_t value;
	int8_t reg;
	int ind;
	int8_t args;

	printf("LLD(%d): Cycle = %ld  POS = %d ", car->id, vm->current_cycle, car->position);
	args = vm->arena[(car->position + 1) % MEM_SIZE];
	if (check_arg(args) == DIR_CODE && check_arg(args << 2) == REG_CODE)
	{
		value = read_four_bytes(vm, (car->position + 2) % MEM_SIZE);
		reg = vm->arena[(car->position + 6) % MEM_SIZE];
		if (reg > 0 && reg <= REG_NUMBER)
			set_reg(car, reg, value, 1);
	}
	else if (check_arg(args) == IND_CODE && check_arg(args << 2) == REG_CODE)
	{
		ind = calc_pos(car, (read_two_bytes(vm, (car->position + 2) % MEM_SIZE)));
		// value = read_four_bytes(vm, ind);
		value = read_two_bytes(vm, ind);
		reg = vm->arena[(car->position + 4) % MEM_SIZE];
		if (reg > 0 && reg <= REG_NUMBER)
			set_reg(car, reg, value, 1);
	}
	car->position = calc_pos(car, get_arg_step(args, 2, DIR_SIZE));
}
