/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:47:33 by ediego            #+#    #+#             */
/*   Updated: 2020/05/14 16:28:22 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

void 		op_sub(t_vm *vm, t_car *car, t_arg *arg)
{
	arg->first = determine_arg(vm->arena[get_pos(car, car->step)], 0);
	arg->sec_d = determine_arg(vm->arena[get_pos(car, car->step)], 1);
	arg->third = determine_arg(vm->arena[get_pos(car, car->step)], 2);
	if (arg->first == REG && arg->sec_d == REG && arg->third == REG)
		write_to_reg_a_s(vm, car, arg, MINUS);
	change_position(vm, car, arg, THREE);
}
