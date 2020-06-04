/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_with_args2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:22:22 by ediego            #+#    #+#             */
/*   Updated: 2020/05/26 12:22:24 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

int				check_arg(uint8_t arg)
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

int				get_arg_n(t_vm *vm, t_car *car, int8_t args)
{
	int32_t		res;
	int32_t		value;

	res = 0;
	if (check_arg(args) == REG_CODE)
	{
		value = (vm->arena[(car->position + car->step) % MEM_SIZE]);
		res = car->registers[--value];
		car->step += 1;
	}
	else if (check_arg(args) == DIR_CODE)
	{
		res = read_two_bytes(vm, (car->position + car->step) % MEM_SIZE);
		car->step += 2;
	}
	else if (check_arg(args) == IND_CODE)
	{
		value = read_two_bytes(vm, (car->position + car->step) % MEM_SIZE);
		res = read_four_bytes(vm, get_pos(car, get_idx(value)));
		car->step += 2;
	}
	return (res);
}

int				get_arg_step(int args, int num, int dir_size)
{
	int			sum;
	int			bit;

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
		bit += 2;
	}
	return (++sum);
}

bool			valid_args(t_vm *vm, t_car *car, int8_t args)
{
	bool		res;
	int8_t		arg1;
	int8_t		arg2;
	int8_t		arg3;

	arg1 = check_arg(args);
	arg2 = check_arg(args << 2);
	arg3 = check_arg(args << 4);
	res = false;
	if ((arg1 == REG_CODE || arg1 == DIR_CODE || arg1 == IND_CODE) &&
	(arg2 == REG_CODE || arg2 == DIR_CODE) && (arg3 == REG_CODE))
		res = true;
	if (arg1 == REG_CODE && invalid_reg(vm, car, args, 0))
		res = false;
	if (arg2 == REG_CODE && invalid_reg(vm, car, args, 1))
		res = false;
	if (arg3 == REG_CODE && invalid_reg(vm, car, args, 2))
		res = false;
	car->step = 2;
	return (res);
}
