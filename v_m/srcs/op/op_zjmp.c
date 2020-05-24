/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 18:39:34 by ediego            #+#    #+#             */
/*   Updated: 2020/05/24 13:22:02 by enshertid        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

void 		op_zjmp(t_vm *vm, t_car *car, t_arg *arg)
{
	int dir;
	
	(void)arg->first;
	// if (vm->debug)
	// 	printf("ZJMP(%d): Cycle = %d Pos = %d", car->id, vm->current_cycle, car->position);
	if (car->carry)
	{
		dir = read_two_bytes(vm, (car->position + 1) % MEM_SIZE);
		car->position = get_pos(car, get_idx(dir));
		// if (vm->debug)
		// 	printf(" DIR = %d jump to %d \n", dir, car->position);
	}
	else
	{
		car->position = (car->position + 3) % MEM_SIZE;
		// if (vm->debug)
		// 	printf(" carry = %d End position %d\n", car->carry, car->position);
	}
}
