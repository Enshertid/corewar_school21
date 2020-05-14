/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:45:14 by ediego            #+#    #+#             */
/*   Updated: 2020/05/14 16:15:40 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

static void		write_to_reg(t_car *car, int8_t first,
								int8_t second, int8_t third)
{
	car->registers[third] = car->registers[first] + car->registers[second];
	if (!car->registers[first])
		car->carry = TRUE;
	else
		car->carry = FALSE;
}


void			op_add(t_vm *vm, t_car *car) {
	int8_t first;
	int8_t second;
	int8_t third;
	
	printf("ADD(%d) Cycle = %ld Pos = %d ", car->id, vm->current_cycle, car->position);
	first = read_byte(vm, get_new_pos(car->position, car->step)) - 1;
	car->step += REG;
	second = read_byte(vm, get_new_pos(car->position, car->step)) - 1;
	car->step += REG;
	third = read_byte(vm, get_new_pos(car->position, car->step)) - 1;
	car->step += REG;
	if (first >= 0 && first < REG_NUMBER && second >= 0 && second <
	        REG_NUMBER && third >= 0 && third < REG_NUMBER)
		write_to_reg(car, first, second, third);
	car->position = get_new_pos(car->position, car->step);
	car->code = read_byte(vm, car->position) - 1;
	if (car->code >= 0 && car->code < OP_NUM)
		car->cycle_to_action = vm->operations.op_cycles[car->code];
	car->step = OP_BYTE;
	printf(" End %d ", car->position);
}
