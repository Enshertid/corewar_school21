/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 18:39:34 by ediego            #+#    #+#             */
/*   Updated: 2020/05/07 18:41:51 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int 		get_pos(t_vm *vm, t_car *car)
{
	int32_t	pos;
	int8_t 	b1;
	int8_t 	b2;

	pos = 0;
	b1 = (vm->arena[car->position + 1]) % MEM_SIZE;
	b2 = (vm->arena[car->position + 2]) % MEM_SIZE;
	pos = (pos | b2) >> 8;
	pos = (pos | b1);
	return(pos);
}

void 		op_zjmp(t_vm *vm, t_car *car)
{
<<<<<<< HEAD
	//done
	vm->dump_value = 1000; // delete this
	if (!car->registers[1])
		car->cycle_to_action = 20;
=======
	if (car->carry)
	{
		car->position += get_pos(vm, car);
		car->position %= IDX_MOD;
	}
	else
		car->position++;
>>>>>>> fcb35621be3e46b074df0cb9c856c36e57defe67
}
