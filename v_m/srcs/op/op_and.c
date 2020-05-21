/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:52:16 by ediego            #+#    #+#             */
/*   Updated: 2020/05/02 17:53:51 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

void 		op_and(t_vm *vm, t_car *car, t_arg *arg)
{
	int8_t	first;
	int8_t	sec;
	int8_t	third;
	int32_t	first_arg;
	int32_t	second_arg;
	
	(void)arg->first;
	first = determine_arg(vm->arena[get_new_pos(car->position, car->step)], 0);
	sec = determine_arg(vm->arena[get_new_pos(car->position, car->step)], 1);
	third = determine_arg(vm->arena[get_new_pos(car->position, car->step)], 2);
	car->step += ARG_CHECK;
	if (first != 0 && sec != 0 && third != 0)
		if (get_arg_dir_four(vm, car, first, &first_arg))
			if (get_arg_dir_four(vm, car, sec, &second_arg))
				write_to_reg(vm, car, (first_arg & second_arg), third);
	change_position(vm, car, OP_BYTE + ARG_CHECK + first + sec + third);
}
