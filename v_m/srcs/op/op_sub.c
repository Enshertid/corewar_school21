/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:47:33 by ediego            #+#    #+#             */
/*   Updated: 2020/05/13 15:29:01 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

void 		op_sub(t_vm *vm, t_car *car)
{
	int8_t first;
	int8_t second;
	int8_t third;
	
	first = read_byte(vm, get_new_pos(car->position, car->step)) - 1;
	car->step += REG;
	second = read_byte(vm, get_new_pos(car->position, car->step)) - 1;
	car->step += REG;
	third = read_byte(vm, get_new_pos(car->position, car->step)) - 1;
	car->step += REG;
	if (first >= 0 && first < REG_NUMBER && second >= 0 && second <
	        REG_NUMBER && third >= 0 && third < REG_NUMBER)
	{
		car->registers[third] = car->registers[first] - car->registers[second];
		if (!car->registers[third])
			car->carry = TRUE;
		else
			car->carry = FALSE;
	}
	car->position = get_new_pos(car->position, car->step);
	car->code = read_byte(vm, car->position) - 1;
	if (car->code >= 0 && car->code < OP_NUM)
		car->cycle_to_action = vm->operations.op_cycles[car->code];
	car->step = OP_BYTE;
}
