/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 15:57:24 by ediego            #+#    #+#             */
/*   Updated: 2020/05/07 17:30:56 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int 		check_arg1(t_vm *vm, t_car *car)
{
	char b1;
	char b2;
	char b3;
	int arg;
	
	b1 = 0x01;
	b2 = 0x02;
	b3 = 0x03;
	arg = vm->arena[(car->position + 1) % MEM_SIZE];
	if (b1 &= (arg >> 6))
		return (1);
	else if (b2 &= (arg >> 6))
		return (2);
	else if (b3 &= (arg >> 6))
		return (3);
}

int 		check_arg2(t_vm *vm, t_car *car)
{
	char b1;
	char b2;
	char b3;
	int arg;
	
	b1 = 0x01;
	b2 = 0x02;
	b3 = 0x03;
	arg = vm->arena[(car->position + 1) % MEM_SIZE];
	arg = arg << 2;
	if (b1 &= (arg >> 6))
		return (1);
	else if (b2 &= (arg >> 6))
		return (2);
	else if (b3 &= (arg >> 6))
		return (3);
}

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

int 		get_pos(t_vm *vm, t_car *car)
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

void 		op_ld(t_vm *vm, t_car *car)
{
	int value;
	int8_t reg;
	int ind;

	if (check_arg1 == 2)
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
		car->position = (car->position + 7) % MEM_SIZE;
	}
	else if (check_arg1 == 3)
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
		car->position = (car->position + 5) % MEM_SIZE;
	}
}
