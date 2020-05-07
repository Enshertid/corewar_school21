/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 15:53:09 by ediego            #+#    #+#             */
/*   Updated: 2020/05/07 13:50:48 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void 		op_live(t_vm *vm, t_car *car)
{
<<<<<<< HEAD
	//done
	vm->count_live++;
	car->last_live_cycle = 0;
	if (!car->registers[1])
		car->cycle_to_action = 10;
=======
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
>>>>>>> fcb35621be3e46b074df0cb9c856c36e57defe67
}
