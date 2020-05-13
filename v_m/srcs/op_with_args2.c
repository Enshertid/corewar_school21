/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_with_args2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 21:28:51 by ediego            #+#    #+#             */
/*   Updated: 2020/05/13 15:30:44 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

int 		check_arg(uint8_t arg)
{
	arg = (arg >> 6) & 0x03;
	if ((uint8_t)0x01 == arg)
		return (REG_CODE);
	else if ((uint8_t)0x02 == arg)
		return (DIR_CODE);
	else if ((uint8_t)0x03 == arg)
		return (IND_CODE);
	return (0);
}

int 		get_arg_n(t_vm *vm, t_car *car, int8_t args)
{
	int32_t res;
	int32_t reg;

	res = 0;
	if (check_arg(args) == REG_CODE)
	{
		reg = vm->arena[(car->position + car->step) % MEM_SIZE];
		res = car->registers[reg];
		car->step += 1;
	}
	else if (check_arg(args) == DIR_CODE)
	{
		res = read_two_bytes(vm, car->position + car->step);
		car->step += 2;
	}
	else if (check_arg(args) == IND_CODE)
	{
		res = (read_two_bytes(vm, car->position + car->step)) % IDX_MOD;
		car->step += 4;
	}
	return (res);
}

void 		set_reg(t_car *car, int8_t reg, int32_t value)
{
	if (reg >= 0 && reg <= 15)
	{
		if (!value)
			car->carry = 1;
		else
			car->carry = 0;
		car->registers[reg] = value;
	}	
}

int 		get_arg_step(int args, int num, int dir_size)
{
	int sum;
	int bit;

	sum = 1;
	bit = 0;
	while (num--)
	{
		if (check_arg(args << bit) == REG_CODE)
			sum += 1;
		else if (check_arg(args << bit) == DIR_CODE)
			sum += dir_size;
		else if (check_arg(args << bit) == IND_CODE)
			sum += 2;
		else
			break ;
		bit += 2;
	}
	return (++sum);
}
