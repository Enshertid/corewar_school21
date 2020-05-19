/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:58:35 by ediego            #+#    #+#             */
/*   Updated: 2020/05/19 21:49:41 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

void 		op_xor(t_vm *vm, t_car *car)
{
	int8_t	first;
	int8_t	sec;
	int8_t	third;
	int32_t	first_arg;
	int32_t	second_arg;
	
	if (vm->debug)
		printf ("XOR(%d):cycle=%zu \n", car->id, vm->current_cycle);
	first = determine_arg(vm->arena[get_new_pos(car->position, car->step)], 0);
	sec = determine_arg(vm->arena[get_new_pos(car->position, car->step)], 1);
	third = determine_arg(vm->arena[get_new_pos(car->position, car->step)], 2);
	car->step += ARG_CHECK;
	if (first != 0 && sec != 0 && third != 0)
		if (get_arg_dir_four(vm, car, first, &first_arg))
			if (get_arg_dir_four(vm, car, sec, &second_arg))
				write_to_reg(vm, car, (first_arg ^ second_arg), third);
	change_position(vm, car, OP_BYTE + ARG_CHECK + first + sec + third);
}
