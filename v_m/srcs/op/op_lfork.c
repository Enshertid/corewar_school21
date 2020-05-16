/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 18:46:32 by ediego            #+#    #+#             */
/*   Updated: 2020/05/16 21:30:22 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

void 		op_lfork(t_vm *vm, t_car *car)
{
	t_car	*new;
	int32_t pos;
	int32_t x;

	printf("LFORK(%d): Cycle = %ld Car->pos = %d carry = %d ", car->id, vm->current_cycle, car->position, car->carry);
	// x = get_2byte(vm, car->position + 1) % IDX_MOD;
	x = read_two_bytes(vm, car->position + 1);
	pos = car->position + x;
	new = copy_caret(car, (pos % MEM_SIZE), ++vm->id_cars);
	add_caret(&vm->carriages, new);
	car->position = (car->position + 3) % MEM_SIZE;
	printf("In end: Car->pos = %d NEW->pos = %d\n", car->position, new->position);
	// car->code = vm->arena[car->position] - 1;
	// if (car->code >= 0 && car->code < 16)
	// 	car->cycle_to_action = vm->operations.op_cycles[car->code];
}
