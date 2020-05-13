/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 18:44:25 by ediego            #+#    #+#             */
/*   Updated: 2020/05/12 22:41:20 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void 		op_lldi(t_vm *vm, t_car *car)
{
	int8_t args;
	int32_t addr;
	int32_t arg1;
	int32_t value;

	car->step = 2;
	args = vm->arena[(car->position + 1) % MEM_SIZE];
	arg1 = get_arg_n(vm, car, args);
	addr = car->position + (arg1 + get_arg_n(vm, car, args << 2));
	value = read_four_bytes(vm, addr);
	set_reg(car, vm->arena[(car->position + car->step) % MEM_SIZE], value);
	car->position += get_arg_step(args, 2, DIR_SIZE / 2);
}
