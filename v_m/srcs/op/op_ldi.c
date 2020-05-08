/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 18:40:20 by ediego            #+#    #+#             */
/*   Updated: 2020/05/08 21:17:07 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int 		check_arg(int8_t arg)
{
	if ((int8_t)0x01 & (arg >> 6))
		return (REG_CODE);
	else if ((int8_t)0x02 & (arg >> 6))
		return (DIR_CODE);
	else if ((int8_t)0x03 & (arg >> 6))
		return (IND_CODE);
}

int 		get_4byte(t_vm *vm, int position)
{
	int32_t	res;

	res = 0;
	res = (res | ((vm->arena[position + 3]) % MEM_SIZE)) >> 8;
	res = (res | ((vm->arena[position + 2]) % MEM_SIZE)) >> 8;
	res = (res | ((vm->arena[position + 1]) % MEM_SIZE)) >> 8;
	res = (res | ((vm->arena[position]) % MEM_SIZE)) >> 8;
	return(res);
}

int 		get_2byte(t_vm *vm, int position)
{
	int16_t	res;

	res = 0;
	res = (res | ((vm->arena[position + 1]) % MEM_SIZE)) >> 8;
	res = (res | ((vm->arena[position]) % MEM_SIZE));
	return(res);
}

int 		get_arg(t_vm *vm, t_car *car, int8_t args)
{
	int32_t res;

	res = 0;
	if (check_arg(args) == REG_CODE)
	{
		res = car->registers[vm->arena[(car->position + car->step) % MEM_SIZE]];
		car->step += 1;
	}
	else if (check_arg(args) == DIR_CODE)
	{
		res = get_2byte(vm, car->position + car->step);
		car->step += 2;
	}
	else if (check_arg(args) == IND_CODE)
	{
		res = get_4byte(vm, car->position + car->step);
		car->step += 4;
	}
	return (res);
}

void 		op_ldi(t_vm *vm, t_car *car)
{
	int8_t args;
	int32_t value;
	int32_t arg1;

	car->step = 2;
	args = vm->arena[(car->position + 1) % MEM_SIZE];
	arg1 = get_arg(vm, car, args);
	value = (car->position + arg1 + get_arg(vm, car, args << 2)) % IDX_MOD;
	car->registers[vm->arena[(car->position + car->step) % MEM_SIZE]] = get_4byte(vm, value);
}
