/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:17:10 by ediego            #+#    #+#             */
/*   Updated: 2020/05/26 12:17:11 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				op_lldi(t_vm *vm, t_car *car, t_arg *arg)
{
	int8_t			args;
	int32_t			sum;
	int32_t			pos;
	int32_t			value;
	int32_t			reg3;

	(void)arg->first;
	car->step = 2;
	args = vm->arena[(car->position + 1) % MEM_SIZE];
	if (valid_args(vm, car, args))
	{
		sum = get_arg_n(vm, car, args) + get_arg_n(vm, car, args << 2);
		pos = get_pos(car, sum);
		value = read_four_bytes(vm, pos);
		reg3 = vm->arena[(car->position + car->step) % MEM_SIZE];
		set_reg(car, reg3, value, 1);
	}
	car->position = get_pos(car, get_arg_step(args, 3, DIR_SIZE / 2));
	car->step = OP_BYTE;
}
