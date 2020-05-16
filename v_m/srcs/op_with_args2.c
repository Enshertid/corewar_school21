/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_with_args2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 21:28:51 by ediego            #+#    #+#             */
/*   Updated: 2020/05/16 13:30:05 by ediego           ###   ########.fr       */
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
	int32_t value;
	int32_t pos;

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
		pos = car->position + get_idx(value);
		res = read_four_bytes(vm, pos);
		car->step += 4;
	}
	return (res);
}

void 		set_reg(t_car *car, int8_t reg, int32_t value, t_bool carry)
{
	if (carry)
	{
		if (!value)
			car->carry = 1;
		else
			car->carry = 0;
	}
	car->registers[--reg] = value;
	printf(" reg = %d value = %d ", ++reg, value);
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
		{
			sum = 0; // maybe delete this ?
			break ;
		}
		bit += 2;
	}
	return (++sum);
}

t_bool 		invalid_reg(t_vm *vm, t_car *car, int8_t args, int num)
{
	int8_t reg;
	int32_t pos;

	pos = car->position + get_arg_step(args, num, DIR_SIZE/2);
	reg = (vm->arena[pos % MEM_SIZE]);
	if (reg < 1 || reg > 16)
		return(TRUE);
	car->step += 1;
	return(FALSE);
}

t_bool 	valid_args(t_vm *vm, t_car *car, int8_t args)
{
	t_bool res;
	int8_t arg1;
	int8_t arg2;
	int8_t arg3;
	
	arg1 = check_arg(args);
	arg2 = check_arg(args << 2);
	arg3 = check_arg(args << 4);
	res = FALSE;
	if ((arg1 == REG_CODE || arg1 == DIR_CODE ||	arg1 == IND_CODE) &&
	(arg2 == REG_CODE || arg2 == DIR_CODE) && (arg3 == REG_CODE))
		res = TRUE;
	if (arg1 == REG_CODE && invalid_reg(vm, car, args, 0))
		res = FALSE;
	if (arg2 == REG_CODE && invalid_reg(vm, car, args, 1))
		res = FALSE;
	if (arg3 == REG_CODE && invalid_reg(vm, car, args, 2))
		res = FALSE;
	car->step = 2;
	return(res);
}

t_bool 	valid_args2(t_vm *vm, t_car *car, int8_t args)
{
	t_bool res;
	int8_t arg1;
	int8_t arg2;
	int8_t arg3;
	
	arg1 = check_arg(args);
	arg2 = check_arg(args << 2);
	arg3 = check_arg(args << 4);
	res = FALSE;
	if ((arg1 == REG_CODE || arg1 == DIR_CODE ||	arg1 == IND_CODE) &&
	(arg2 == REG_CODE || arg2 == DIR_CODE || arg2 == IND_CODE) &&
	(arg3 == REG_CODE))
		res = TRUE;
	if (arg1 == REG_CODE && invalid_reg(vm, car, args, 0))
		res = FALSE;
	if (arg2 == REG_CODE && invalid_reg(vm, car, args, 1))
		res = FALSE;
	if (arg3 == REG_CODE && invalid_reg(vm, car, args, 2))
		res = FALSE;
	car->step = 2;
	return(res);
}

int 		calc_pos(t_car *car, int pos)
{
	pos = car->position + pos;
	if (pos < 0 && -pos > MEM_SIZE)
	{
		pos = -pos % MEM_SIZE;
		pos *= -1;
	}
	else if(pos < 0)
		pos = MEM_SIZE + pos;
	else
		pos = pos % MEM_SIZE;
	return(pos);
}

int 	get_idx(int value)
{
	int result;

	if (value < 0)
	{
		result = (-1 * value) % IDX_MOD;
		result *= -1;
	}
	else
		result = value % IDX_MOD;
	return(result);
}
