/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 18:39:34 by ediego            #+#    #+#             */
/*   Updated: 2020/05/11 11:20:32 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

void 		op_zjmp(t_vm *vm, t_car *car)
{
	printf("ZJMP: Cycle = %ld pos = %d", vm->current_cycle, car->position);
	if (car->carry)
		car->position += (get_2byte(vm, car->position + 1) % IDX_MOD) % MEM_SIZE;
	else
		car->position = (car->position + 3) % MEM_SIZE;
	car->code = vm->arena[car->position] - 1;
	if (car->code >= 0 && car->code < 16)
		car->cycle_to_action = vm->operations.op_cycles[car->code] - 1;
	printf(" jump to %d\n", car->position);
}
