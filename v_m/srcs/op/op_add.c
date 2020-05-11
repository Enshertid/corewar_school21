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

void			op_add(t_vm *vm, t_car *car)
{
	int8_t first;
	int8_t second;
	int8_t third;
	
	car->step = OP_BYTE;
	first = read_byte(vm, ((car->position + car->step) % MEM_SIZE));
	second = read_byte(vm, ((car->position + car->step + REG) % MEM_SIZE));
	third = read_byte(vm, ((car->position + car->step + REG * 2) % MEM_SIZE));
	if (first >= 1 && first < 16 && second >= 1 && second < 16 &&
											third >= 1 && third < 16)
		write_to_reg(car, first, second, third);
	car->step += REG * 2;
	car->position = (car->position + car->step) % MEM_SIZE;
	car->code = vm->arena[car->position] - 1;
	if (car->code >= 0 && car->code < 16)
		car->cycle_to_action = vm->operations.op_cycles[car->code] - 1;
}
