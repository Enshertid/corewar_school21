/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:47:33 by ediego            #+#    #+#             */
/*   Updated: 2020/05/02 17:48:39 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

void 		op_sub(t_vm *vm, t_car *car)
{
	int8_t first;
	int8_t second;
	int8_t third;
	
	first = read_byte(vm, ((car->position + REG) % MEM_SIZE));
	second = read_byte(vm, ((car->position + REG * 2) % MEM_SIZE));
	third = read_byte(vm, ((car->position + REG * 3) % MEM_SIZE));
	if (first >= 1 && first < 16 && second >= 1 && second < 16 &&
										third >= 1 && third < 16)
	{
		car->registers[third] = car->registers[first] - car->registers[second];
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
