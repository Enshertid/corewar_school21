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

void 		op_sub(t_vm *vm, t_car *car)
{
	int8_t first;
	int8_t sec;
	int8_t third;
	
	first = determine_arg(vm->arena[get_new_pos(car->position, car->step)], 0);
	sec = determine_arg(vm->arena[get_new_pos(car->position, car->step)], 1);
	third = determine_arg(vm->arena[get_new_pos(car->position, car->step)], 2);
	if (first == REG && sec == REG && third == REG)
		write_to_reg_a_s(vm, car, MINUS);
	change_position(vm, car, OP_BYTE + ARG_CHECK + first + sec + third);
}
