/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:45:14 by ediego            #+#    #+#             */
/*   Updated: 2020/05/02 17:46:43 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

static void		write_to_reg(t_car *car, int8_t first,
								int8_t second, int8_t third)
{
	car->registers[first] = car->registers[second] + car->registers[third];
	if (!car->registers[first])
		car->carry = TRUE;
	else
		car->carry = FALSE;
}

static t_bool		check_determine(t_vm *vm, t_car *car)
{
	if (determine_arg(read_byte(vm,
								get_new_pos(car->position, car->step)), 0) == REG)
		if (determine_arg(read_byte(vm,
									get_new_pos(car->position, car->step)), 1) != REG)
			if (determine_arg(read_byte(vm,
										get_new_pos(car->position, car->step)), 2) != REG)
			{
				car->step++;
				return(TRUE);
			}
	car->step++;
	return (FALSE);
}

void			op_add(t_vm *vm, t_car *car) {
	int8_t first;
	int8_t second;
	int8_t third;
	
	if (check_determine(vm, car))
	{
		first = read_byte(vm, get_new_pos(car->position, car->step));
		car->step += REG;
		second = read_byte(vm, get_new_pos(car->position, car->step));
		car->step += REG;
		third = read_byte(vm, get_new_pos(car->position, car->step));
		car->step += REG;
		if (first >= 1 && first < 16 && second >= 1 && second < 16 &&
			third >= 1 && third < 16)
			write_to_reg(car, first, second, third);
	}
	car->position = get_new_pos(car->position, car->step);
	car->code = read_byte(vm, car->position) - 1;
	if (car->code >= 0 && car->code < OP_NUM)
		car->cycle_to_action = vm->operations.op_cycles[car->code];
	car->step = OP_BYTE;
}
