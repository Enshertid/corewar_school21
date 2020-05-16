/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 18:47:13 by ediego            #+#    #+#             */
/*   Updated: 2020/05/13 15:30:14 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"
#include "stdio.h"

void 		op_aff(t_vm *vm, t_car *car)
{
	int8_t		arg;
	int8_t		reg;
	
	arg = determine_arg(vm->arena[get_new_pos(car->position, car->step)], 0);
	car->step += ARG_CHECK;
	if (arg == REG)
	{
		reg = read_byte(vm, get_new_pos(car->position, car->step)) - 1;
		if (reg >= 0 && reg < REG_NUMBER)
			printf ("%c", (char)car->registers[reg]);
	}
	change_position(vm, car, OP_BYTE + ARG_CHECK + arg);
}
