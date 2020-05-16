/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 18:40:20 by ediego            #+#    #+#             */
/*   Updated: 2020/05/16 16:16:57 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

void 		op_ldi(t_vm *vm, t_car *car)
{
	int8_t args;
	int32_t sum;
	int32_t pos;
	int32_t value;
	int32_t reg3;

	printf("LDI(%d): Cycle = %ld  POS = %d ", car->id, vm->current_cycle, car->position);
	car->step = 2;
	args = vm->arena[(car->position + 1) % MEM_SIZE];
	if (valid_args(vm, car, args))
	{
		sum = get_arg_n(vm, car, args) + get_arg_n(vm, car, args << 2);
		pos = calc_pos(car, get_idx(sum));
		value = read_four_bytes(vm, pos);
		reg3 = vm->arena[(car->position + car->step) % MEM_SIZE];
		printf(" SUM = %d POS = %d VALUE = %d ", sum, pos, value);
		set_reg(car, reg3, value, 0);
	}
	car->position += get_arg_step(args, 3, DIR_SIZE / 2);
	car->step = OP_BYTE;
	printf(" END pos = %d\n", car->position);
}
