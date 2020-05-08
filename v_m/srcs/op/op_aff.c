/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 18:47:13 by ediego            #+#    #+#             */
/*   Updated: 2020/05/02 18:47:25 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"
#include "stdio.h"

void 		op_aff(t_vm *vm, t_car *car)
{
	printf ("%c", (char)vm->arena[(car->position + 1) % MEM_SIZE]);
	car->position = (car->position + 2) % MEM_SIZE;
	car->code = vm->arena[car->position] - 1;
	if (car->code >= 0 && car->code < 16)
		car->cycle_to_action = vm->operations.op_cycles[car->code] - 1;
	else
		car->position = (car->position + 1) % MEM_SIZE;
}
