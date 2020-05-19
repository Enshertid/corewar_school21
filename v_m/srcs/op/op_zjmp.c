/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 18:39:34 by ediego            #+#    #+#             */
/*   Updated: 2020/05/19 21:54:38 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

void 		op_zjmp(t_vm *vm, t_car *car)
{
	int dir;
	int new_pos;

	if (vm->debug)
		printf("ZJMP(%d): Cycle = %ld Pos = %d", car->id, vm->current_cycle, car->position);
	if (car->carry)
	{
		dir = read_two_bytes(vm, (car->position + 1) % MEM_SIZE);
		new_pos = get_idx(dir);
		car->position = calc_pos(car, new_pos);
		if (vm->debug)
			printf(" DIR = %d jump to %d \n", dir, car->position);
	}
	else
	{
		car->position = (car->position + 3) % MEM_SIZE; // car->pos + 3
		if (vm->debug)
			printf(" carry = %d End position %d\n", car->carry, car->position);
	}
}
