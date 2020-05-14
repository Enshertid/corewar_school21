/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 18:40:20 by ediego            #+#    #+#             */
/*   Updated: 2020/05/14 14:59:28 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

static t_bool 		invalid_reg(t_vm *vm, t_car *car, int8_t args, int num)
{
	int8_t reg;
	int32_t pos;

	pos = car->position + get_arg_step(args, num, DIR_SIZE/2);
	reg = (vm->arena[pos % MEM_SIZE]);
	if (reg < 1 || reg > 16) {
		// printf(" INVALID=%d pos =%d", reg, pos);
		return(TRUE);
	}
	car->step += 1;
	return(FALSE);
}

static t_bool 	valid_args(t_vm *vm, t_car *car, int8_t args)
{
	t_bool res;
	int8_t arg1;
	int8_t arg2;
	int8_t arg3;
	
	arg1 = check_arg(args);
	arg2 = check_arg(args << 2);
	arg3 = check_arg(args << 4);
	res = FALSE;
	if ((arg1 == REG_CODE || arg1 == DIR_CODE ||	arg1 == IND_CODE) &&
	(arg2 == REG_CODE || arg2 == DIR_CODE) && (arg3 == REG_CODE))
		res = TRUE;
	if (arg1 == REG_CODE && invalid_reg(vm, car, args, 0))
	{
		// printf(" here 1 ");
		res = FALSE;
	}
	if (arg2 == REG_CODE && invalid_reg(vm, car, args, 1)) {
		// printf(" here 2 ");
		res = FALSE;
		}
	if (arg3 == REG_CODE && invalid_reg(vm, car, args, 2)) {
		// printf(" here 3 ");
		res = FALSE;
		}
	car->step = 2;
	return(res);
}

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
