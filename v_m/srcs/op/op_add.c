/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:45:14 by ediego            #+#    #+#             */
/*   Updated: 2020/05/14 16:27:48 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

void			op_add(t_vm *vm, t_car *car) {
	int8_t first;
	int8_t sec;
	int8_t third;
	
	printf("ADD(%d) Cycle = %ld Pos = %d ", car->id, vm->current_cycle, car->position);
	first = determine_arg(vm->arena[get_new_pos(car->position, car->step)], 0);
	sec = determine_arg(vm->arena[get_new_pos(car->position, car->step)], 1);
	third = determine_arg(vm->arena[get_new_pos(car->position, car->step)], 2);
	if (first == REG && sec == REG && third == REG)
		write_to_reg_a_s(vm, car, PLUS);
	change_position(vm, car, OP_BYTE + ARG_CHECK + first + sec + third);
	printf(" End %d \n", car->position);
}
