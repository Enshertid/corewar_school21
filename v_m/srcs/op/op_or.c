/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:17:32 by ediego            #+#    #+#             */
/*   Updated: 2020/05/26 12:17:33 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

void				op_or(t_vm *vm, t_car *car, t_arg *arg)
{
	int32_t			value;

	arg->first = determine_arg(vm->arena[get_pos(car, car->step)], 0);
	arg->sec_d = determine_arg(vm->arena[get_pos(car, car->step)], 1);
	arg->third = determine_arg(vm->arena[get_pos(car, car->step)], 2);
	car->step += ARG_CHECK;
	if (arg->first != 0 && arg->sec_d != 0 && arg->third != 0 &&
		get_arg_dir_four(vm, car, arg->first, &arg->first_val) &&
		get_arg_dir_four(vm, car, arg->sec_d, &arg->sec_d_val))
	{
		value = arg->first_val | arg->sec_d_val;
		write_to_reg(vm, car, value, arg->third);
	}
	change_position(car, arg, THREE);
}
