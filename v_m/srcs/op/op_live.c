/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 15:53:09 by ediego            #+#    #+#             */
/*   Updated: 2020/05/07 13:30:21 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void 		op_live(t_vm *vm, t_car *car)
{
	int8_t arg;

	arg = (car->position + 1) % MEM_SIZE;
	vm->count_live++;
	car->last_live_cycle = vm->current_cycle;
	if (arg <= -1 && arg >= -(vm->players->size))
	{
		vm->players->arr[arg]->live = vm->current_cycle;
		vm->last_live_id = arg;
	}
}
