/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_with_args2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 21:28:51 by ediego            #+#    #+#             */
/*   Updated: 2020/05/09 00:35:46 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

int 		check_arg(int8_t arg)
{
	if ((int8_t)0x01 & (arg >> 6))
		return (REG_CODE);
	else if ((int8_t)0x02 & (arg >> 6))
		return (DIR_CODE);
	else if ((int8_t)0x03 & (arg >> 6))
		return (IND_CODE);
}

int 		get_2byte(t_vm *vm, int position)
{
	int16_t	res;

	res = 0;
	position = position % MEM_SIZE;
	res = (res | ((vm->arena[position + 1]) % MEM_SIZE)) >> 8;
	res = (res | ((vm->arena[position]) % MEM_SIZE));
	return(res);
}

int 		get_4byte(t_vm *vm, int position)
{
	int32_t	res;

	res = 0;
	position = position % MEM_SIZE;
	res = (res | ((vm->arena[position + 3]) % MEM_SIZE)) >> 8;
	res = (res | ((vm->arena[position + 2]) % MEM_SIZE)) >> 8;
	res = (res | ((vm->arena[position + 1]) % MEM_SIZE)) >> 8;
	res = (res | ((vm->arena[position]) % MEM_SIZE)) >> 8;
	return(res);
}

int 		get_arg_n(t_vm *vm, t_car *car, int8_t args)
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
		res = (get_2byte(vm, car->position + car->step)) % IDX_MOD;
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
			sum += 2;
		else if (check_arg(args << bit) == DIR_CODE)
			sum += dir_size + 1;
		else if (check_arg(args << bit) == IND_CODE)
			sum += 3;
		else
			break ;
		bit += 2;
	}
	return (sum);
}
