/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 13:31:33 by ediego            #+#    #+#             */
/*   Updated: 2020/05/21 00:31:18 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

void 		op_fork(t_vm *vm, t_car *car, t_arg *arg)
{
	t_car	*new;
	int32_t pos;
	int32_t dir;

	(void)arg->first;
	// if (vm->debug)
	// 	printf("FORK(%d): Cycle = %d Car->pos = %d carry = %d ", car->id, vm->current_cycle, car->position, car->carry);
	dir = read_two_bytes(vm, (car->position + 1) % MEM_SIZE) % IDX_MOD;
	pos = get_pos(car, dir);
	new = copy_caret(car, pos, ++vm->id_cars); // check this ?!
	add_caret(&vm->carriages, new);
	car->position = (car->position + 3) % MEM_SIZE;
	vm->num_of_car++;
	// if (vm->debug)
		// printf("In end: Car->pos = %d NEW->pos = %d\n", car->position, new->position);
}
