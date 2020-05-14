/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 18:40:20 by ediego            #+#    #+#             */
/*   Updated: 2020/05/14 17:14:06 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

void 		op_ldi(t_vm *vm, t_car *car)
{
	int8_t args;
	int32_t arg1;
	int32_t arg2;
	int32_t value;
	int32_t reg3;

	printf("LDI(%d): Cycle = %ld  POS = %d ", car->id, vm->current_cycle, car->position);
	car->step = 2;
	args = vm->arena[(car->position + 1) % MEM_SIZE];
	if (valid_args(vm, car, args))
	{
		arg1 = get_arg_n(vm, car, args);
		arg2 = get_arg_n(vm, car, args << 2);
		value = read_four_bytes(vm, ((car->position + (arg1 + arg2) % IDX_MOD) % MEM_SIZE));
		reg3 = vm->arena[(car->position + car->step) % MEM_SIZE];
		printf(" ARG1 = %d ARG2 = %d REG3 = %d ", arg1, arg2, reg3);
		set_reg(car, reg3, value);
	}
	car->position += get_arg_step(args, 3, DIR_SIZE / 2);
	car->step = OP_BYTE;
	printf(" END pos = %d\n", car->position);
}
