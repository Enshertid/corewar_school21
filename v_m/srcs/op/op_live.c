/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 15:53:09 by ediego            #+#    #+#             */
/*   Updated: 2020/05/10 14:50:19 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

void 		op_live(t_vm *vm, t_car *car)
{
	int8_t arg;
	
	arg = read_reg(vm, get_new_pos(car->position, OP_BYTE));
	vm->count_live++;
	car->last_live_cycle = 0;
	car->position = (car->position + 2) % MEM_SIZE;
	if (arg <= -1 && arg >= -(vm->players->size))
	{
		vm->players->arr[arg]->live = vm->current_cycle;
		vm->last_live_id = arg;
	}
}
