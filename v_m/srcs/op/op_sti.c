/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 13:30:32 by ediego            #+#    #+#             */
/*   Updated: 2020/05/07 18:01:00 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int 		check_arg1(t_vm *vm, t_car *car)
{
	char b1;
	char b2;
	char b3;
	int arg;
	
	b1 = 0x01;
	b2 = 0x02;
	b3 = 0x03;
	arg = vm->arena[(car->position + 1) % MEM_SIZE];
	if (b1 &= (arg >> 6))
		return (1);
	else if (b2 &= (arg >> 6))
		return (2);
	else if (b3 &= (arg >> 6))
		return (3);
}

void 		op_sti(t_vm *vm, t_car *car)
{
<<<<<<< HEAD
	//done
	vm->dump_value = 1000; // delete this
	car->cycle_to_action = 25;
=======
	if (check_arg1 == 1);
>>>>>>> fcb35621be3e46b074df0cb9c856c36e57defe67
}

