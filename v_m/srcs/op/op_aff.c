/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 18:47:13 by ediego            #+#    #+#             */
/*   Updated: 2020/05/02 18:47:25 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"
#include "stdio.h"

void 		op_aff(t_vm *vm, t_car *car)
{
	int8_t	type;
	
	type = determine_arg(read_byte(vm,
			get_new_pos(car->position, car->step)), 0);
	car->step += ARG_CHECK;
	if (type == REG)
		printf ("%c", (char)read_byte(vm,
				get_new_pos(car->position, car->step)));
	car->step += type;
	car->position = get_new_pos(car->position, car->step);
	car->code = read_byte(vm, car->position) - 1;
	if (car->code >= 0 && car->code < OP_NUM)
		car->cycle_to_action = vm->operations.op_cycles[car->code];
	car->step = OP_BYTE;
}
