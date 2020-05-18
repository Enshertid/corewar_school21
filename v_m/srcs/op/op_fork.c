/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 13:31:33 by ediego            #+#    #+#             */
/*   Updated: 2020/05/17 16:57:38 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

void 		op_fork(t_vm *vm, t_car *car)
{
	t_car	*new;
	int32_t pos;
	int32_t x;

//	printf("FORK(%d): Cycle = %ld Car->pos = %d carry = %d ", car->id, vm->current_cycle, car->position, car->carry);
	x = read_two_bytes(vm, (car->position + 1) % MEM_SIZE) % IDX_MOD;
	pos = calc_pos(car, x);
	new = copy_caret(car, pos, ++vm->id_cars);
	add_caret(&vm->carriages, new);
	car->position = (car->position + 3) % MEM_SIZE;
//	printf("In end: Car->pos = %d NEW->pos = %d\n", car->position, new->position);
}
