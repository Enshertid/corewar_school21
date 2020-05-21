/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:45:14 by ediego            #+#    #+#             */
/*   Updated: 2020/05/19 21:21:51 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

void			op_add(t_vm *vm, t_car *car, t_arg *arg)
{
	int8_t first;
	int8_t sec;
	int8_t third;
	
	(void)arg->first;
	if (vm->debug)
		printf("ADD(%d) Cycle: %d Pos = %d ", car->id, vm->current_cycle, car->position);
	first = determine_arg(vm->arena[get_new_pos(car->position, car->step)], 0);
	sec = determine_arg(vm->arena[get_new_pos(car->position, car->step)], 1);
	third = determine_arg(vm->arena[get_new_pos(car->position, car->step)], 2);
	if (first == REG && sec == REG && third == REG)
		write_to_reg_a_s(vm, car, PLUS);
	change_position(vm, car, OP_BYTE + ARG_CHECK + first + sec + third);
	if (vm->debug)
		printf(" End %d \n", car->position);
}
