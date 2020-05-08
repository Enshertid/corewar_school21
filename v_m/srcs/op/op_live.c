/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 15:53:09 by ediego            #+#    #+#             */
/*   Updated: 2020/05/07 20:20:47 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

void 		op_live(t_vm *vm, t_car *car)
{
	int8_t arg;

	arg = (car->position + 1) % MEM_SIZE;
	vm->count_live++;
	car->last_live_cycle = vm->current_cycle;
	car->position = (car->position + 2) % MEM_SIZE;
	if (arg <= -1 && arg >= -(vm->players->size))
	{
		vm->players->arr[arg]->live = vm->current_cycle;
		vm->last_live_id = arg;
	}
}
