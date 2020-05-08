/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 15:57:24 by ediego            #+#    #+#             */
/*   Updated: 2020/05/08 11:11:14 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int 		check_arg(int arg)
{
	if (0x01 & (arg >> 6))
		return (T_REG);
	else if (0x02 & (arg >> 6))
		return (T_DIR);
	else if (0x03 & (arg >> 6))
		return (T_IND);
	return (0);
}

static int 		get_value(t_vm *vm, int position)
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

static int 		get_arg_step(int args, int num)
{
	int sum;
	int bit;

	sum = 1;
	bit = 0;
	while (num--)
	{
		if (check_arg(args << bit) == 1)
			sum += 1;
		else if (check_arg(args << bit) == 2)
			sum += 4;
		else if (check_arg(args << bit) == 3)
			sum += 2;
		bit += 2;
	}
	return (sum);
}

void 		op_ld(t_vm *vm, t_car *car)
{
	int32_t value;
	int8_t reg;
	int ind;
	int args;

	args = vm->arena[(car->position + 1) % MEM_SIZE];
	if (check_arg(args) == T_DIR && check_arg(args << 2) == T_REG)
	{
		value = get_value(vm, ++car->position);
		reg = vm->arena[car->position + 6];
		if (reg >= 0 && reg <= 15)
		{
			if (!value)
				car->carry = 1;
			else
				car->carry = 0;
			car->registers[reg] = value;
		}
	}
	else if (check_arg(args) == T_IND && check_arg(args << 2) == T_REG)
	{
		ind = (car->position + get_pos(vm, car)) % IDX_MOD;
		value = get_value(vm, ind);
		reg = vm->arena[car->position + 4];
		if (reg >= 0 && reg <= 15)
		{
			if (!value)
				car->carry = 1;
			else
				car->carry = 0;
			car->registers[reg] = value;
		}
	}
	car->position = get_arg_step(args, 2);
}
