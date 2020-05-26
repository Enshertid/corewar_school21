/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reg_work.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:21:48 by ediego            #+#    #+#             */
/*   Updated: 2020/05/26 12:21:49 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

void			write_to_reg_a_s(t_vm *vm, t_car *car, t_arg *arg, int8_t type)
{
	int32_t		res;

	car->step += ARG_CHECK;
	arg->first_val = read_byte(vm, get_pos(car, car->step)) - 1;
	car->step += REG;
	arg->sec_d_val = read_byte(vm, get_pos(car, car->step)) - 1;
	car->step += REG;
	arg->third_val = read_byte(vm, get_pos(car, car->step)) - 1;
	if (arg->first_val >= 0 && arg->first_val < REG_NUMBER &&
		arg->sec_d_val >= 0 && arg->sec_d_val < REG_NUMBER &&
		arg->third_val >= 0 && arg->third_val < REG_NUMBER)
	{
		if (type == PLUS)
			res = car->registers[arg->first_val] +
					car->registers[arg->sec_d_val];
		else
			res = car->registers[arg->first_val] -
					car->registers[arg->sec_d_val];
		car->registers[arg->third_val] = res;
		if (!res)
			car->carry = true;
		else
			car->carry = false;
	}
}

bool			get_arg_dir_two(t_vm *vm, t_car *car, int8_t *sw_arg,
																int32_t *arg)
{
	if (*sw_arg == REG)
	{
		*arg = read_byte(vm, get_pos(car, car->step)) - 1;
		if (*arg < 0 || *arg >= REG_NUMBER)
			return (false);
		*arg = car->registers[*arg];
	}
	else if (*sw_arg == IND)
		*arg = read_four_bytes(vm, get_pos(car,
					read_two_bytes(vm, get_pos(car, car->step)) % IDX_MOD));
	else if (*sw_arg == DIR)
	{
		*arg = read_two_bytes(vm, get_pos(car, car->step));
		*sw_arg = DIR / 2;
	}
	else
		return (false);
	car->step += *sw_arg;
	return (true);
}

bool			get_arg_dir_four(t_vm *vm, t_car *car, int8_t sw_arg,
																int32_t *arg)
{
	if (sw_arg == REG)
	{
		*arg = read_byte(vm, get_pos(car, car->step)) - 1;
		if (*arg >= 0 && *arg < REG_NUMBER)
			*arg = car->registers[*arg];
		else
			return (false);
	}
	else if (sw_arg == IND)
		*arg = read_four_bytes(vm, get_pos(car,
					read_two_bytes(vm, get_pos(car, car->step)) % IDX_MOD));
	else if (sw_arg == DIR)
		*arg = read_four_bytes(vm, get_pos(car, car->step));
	else
		return (false);
	car->step += sw_arg;
	return (true);
}

bool			check_reg(t_vm *vm, t_car *car, int8_t byte, int32_t *arg)
{
	if (byte != REG)
		return (false);
	*arg = read_byte(vm, get_pos(car, car->step)) - 1;
	car->step += REG;
	if (*arg >= 0 && *arg < REG_NUMBER)
		return (true);
	else
		return (false);
}

void			write_to_reg(t_vm *vm, t_car *car, int32_t result,
															int8_t third)
{
	int8_t reg;

	reg = read_byte(vm, get_pos(car, car->step)) - 1;
	if ((third == REG) && (reg >= 0 && reg < REG_NUMBER))
	{
		car->registers[reg] = result;
		car->carry = result ? false : true;
	}
}
