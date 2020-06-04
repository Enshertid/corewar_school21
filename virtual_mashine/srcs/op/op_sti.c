/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 20:55:05 by user              #+#    #+#             */
/*   Updated: 2020/06/03 20:55:07 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

static bool			get_third(t_vm *vm, t_car *car, int8_t *sw_arg,
														int32_t *value)
{
	if (*sw_arg != REG && *sw_arg != DIR)
		return (false);
	if (*sw_arg == REG)
	{
		*value = read_byte(vm, get_pos(car, car->step)) - 1;
		if (*value < 0 || *value >= REG_NUMBER)
			return (false);
		*value = car->registers[*value];
	}
	else
	{
		*value = read_two_bytes(vm, get_pos(car, car->step));
		*sw_arg = DIR / 2;
	}
	car->step += *sw_arg;
	return (true);
}

void				op_sti(t_vm *vm, t_car *car, t_arg *arg)
{
	int32_t			reg;
	int32_t			p;

	arg->first = determine_arg(vm->arena[get_pos(car, car->step)], 0);
	arg->sec_d = determine_arg(vm->arena[get_pos(car, car->step)], 1);
	arg->third = determine_arg(vm->arena[get_pos(car, car->step)], 2);
	car->step += ARG_CHECK;
	if (arg->first != 0 && arg->sec_d != 0 && arg->third != 0)
		if (check_reg(vm, car, arg->first, &reg) &&
			get_arg_dir_two(vm, car, &arg->sec_d, &arg->sec_d_val) &&
			get_third(vm, car, &arg->third, &arg->third_val))
		{
			p = get_pos(car, get_idx(arg->sec_d_val + arg->third_val));
			write_reg_to_arena(vm, car->registers[reg], p);
		}
	arg->first = arg->first == DIR ? DIR / 2 : arg->first;
	arg->sec_d = arg->sec_d == DIR ? DIR / 2 : arg->sec_d;
	arg->third = arg->third == DIR ? DIR / 2 : arg->third;
	change_position(car, arg, THREE);
}
