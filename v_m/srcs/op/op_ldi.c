/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:15:39 by ediego            #+#    #+#             */
/*   Updated: 2020/05/26 12:15:40 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

void				op_ldi(t_vm *vm, t_car *car, t_arg *arg)
{
	int8_t			args;
	int32_t			sum;
	int32_t			pos;
	int32_t			value;
	int32_t			reg;

	(void)arg->first;
	car->step = OP_BYTE + ARG_CHECK;
	args = vm->arena[(car->position + 1) % MEM_SIZE];
	if (valid_args(vm, car, args))
	{
		sum = get_arg_n(vm, car, args) + get_arg_n(vm, car, args << 2);
		pos = get_pos(car, get_idx(sum));
		value = read_four_bytes(vm, pos);
		reg = vm->arena[(car->position + car->step) % MEM_SIZE];
		set_reg(car, reg, value, 0);
	}
	car->position = get_pos(car, get_arg_step(args, 3, DIR_SIZE / 2));
	car->step = OP_BYTE;
}
