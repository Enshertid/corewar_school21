/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 18:45:07 by ediego            #+#    #+#             */
/*   Updated: 2020/05/08 23:59:26 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

int 		get_value(t_vm *vm, int position)
{
	int32_t	pos;
	int8_t 	b1;
	int8_t 	b2;
	int8_t 	b3;
	int8_t 	b4;

	pos = 0;
	b1 = (vm->arena[position + 1]) % MEM_SIZE;
	b2 = (vm->arena[position + 2]) % MEM_SIZE;
	b3 = (vm->arena[position + 3]) % MEM_SIZE;
	b4 = (vm->arena[position + 4]) % MEM_SIZE;
	pos = (pos | b4) >> 8;
	pos = (pos | b3) >> 8;
	pos = (pos | b2) >> 8;
	pos = (pos | b1) >> 8;
	return(pos);
}

static int 		get_pos(t_vm *vm, t_car *car)
{
	int32_t	pos;
	int8_t 	b1;
	int8_t 	b2;

	pos = 0;
	b1 = (vm->arena[car->position + 1]) % MEM_SIZE;
	b2 = (vm->arena[car->position + 2]) % MEM_SIZE;
	pos = (pos | b2) >> 8;
	pos = (pos | b1);
	return(pos);
}

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
