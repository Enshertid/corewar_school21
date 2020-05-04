/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 18:46:32 by ediego            #+#    #+#             */
/*   Updated: 2020/05/02 18:46:48 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void 		op_lfork(t_vm *vm, t_car *car)
{
	vm->dump_value = 1000; // delete this
	if (!car->registers[1])
		car->cycle_to_action = 1000;
}
