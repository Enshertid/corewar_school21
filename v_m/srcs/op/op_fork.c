/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 13:31:33 by ediego            #+#    #+#             */
/*   Updated: 2020/05/12 13:39:38 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

void 		op_fork(t_vm *vm, t_car *car)
{
	t_car	*new;
	int32_t pos;
	int32_t x;

	printf("FORK: Cycle = %ld Car->pos = %d ",vm->current_cycle, car->position);
	x = get_2byte(vm, car->position + 1) % IDX_MOD;
	pos = car->position + x;
	printf("\nX = %d \n", x);
	new = copy_caret(car, (pos % MEM_SIZE), ++vm->id_cars);
	add_caret(&vm->carriages, new);
	car->position = (car->position + 3) % MEM_SIZE;
	printf("In end: Car->pos = %d NEW->pos = %d\n", car->position, new->position);
	car->code = vm->arena[car->position] - 1;
	if (car->code >= 0 && car->code < 16)
		car->cycle_to_action = vm->operations.op_cycles[car->code];
}
