/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 18:44:25 by ediego            #+#    #+#             */
/*   Updated: 2020/05/02 18:44:43 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void 		op_lldi(t_vm *vm, t_car *car)
{
	//done
	vm->dump_value = 1000; // delete this
	if (!car->registers[1])
		car->cycle_to_action = 50;
}
