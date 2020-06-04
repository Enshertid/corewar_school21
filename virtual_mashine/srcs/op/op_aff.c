/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:14:10 by ediego            #+#    #+#             */
/*   Updated: 2020/05/26 12:14:23 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

void				op_aff(t_vm *vm, t_car *car, t_arg *arg)
{
	int32_t			val;

	arg->first = determine_arg(vm->arena[get_pos(car, car->step)], 0);
	car->step += ARG_CHECK;
	if (arg->first == REG && vm->aff != 0)
	{
		arg->first_val = read_byte(vm, get_pos(car, car->step)) - 1;
		if (arg->first_val >= 0 && arg->first_val < REG_NUMBER)
		{
			val = (char)car->registers[arg->first_val];
			write(1, "AFF: ", 5);
			write(1, &val, 1);
			write(1, "\n", 1);
		}
	}
	change_position(car, arg, ONE);
}
