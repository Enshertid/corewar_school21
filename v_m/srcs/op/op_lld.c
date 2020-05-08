/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 18:45:07 by ediego            #+#    #+#             */
/*   Updated: 2020/05/09 01:08:58 by ediego           ###   ########.fr       */
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

	args = vm->arena[(car->position + 1) % MEM_SIZE];
	if (check_arg(args) == DIR_CODE && check_arg(args << 2) == REG_CODE)
	{
		value = get_4byte(vm, car->position + 2);
		reg = vm->arena[(car->position + 6) % MEM_SIZE];
		set_reg(car, reg, value);
	}
	else if (check_arg(args) == IND_CODE && check_arg(args << 2) == REG_CODE)
	{
		ind = car->position + (get_2byte(vm, car->position + 2));
		value = get_4byte(vm, ind);
		reg = vm->arena[(car->position + 4) % MEM_SIZE];
		set_reg(car, reg, value);
	}
	car->position += get_arg_step(args, 2, DIR_SIZE);
}
