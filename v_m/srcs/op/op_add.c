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

#include "corewar.h"

void 		op_add(t_vm *vm, t_car *car)
{
	int8_t first;
	int8_t second;
	int8_t third;
	
	first = read_reg_arg(vm, ((car->position + REG) % MEM_SIZE));
	second = read_reg_arg(vm, ((car->position + REG * 2) % MEM_SIZE));
	third = read_reg_arg(vm, ((car->position + REG * 3) % MEM_SIZE));
	if (first >= 1 && first < 16 && second >= 1 && second < 16 &&
											third >= 1 && third < 16)
	{
		car->registers[third] = car->registers[first] + car->registers[second];
		if (!car->registers[third])
			car->carry = TRUE;
		else
			car->carry = FALSE;
	}
	car->position = (car->position + REG * 4) % MEM_SIZE;
	car->code = vm->arena[car->position] - 1;
	if (car->code >= 0 && car->code < 16)
		car->cycle_to_action = vm->operations.op_cycles[car->code] - 1;
}
