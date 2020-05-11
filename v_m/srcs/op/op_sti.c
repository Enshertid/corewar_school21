/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 13:30:32 by ediego            #+#    #+#             */
/*   Updated: 2020/05/07 21:55:23 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

static t_bool	check_reg(t_vm *vm, t_car *car, int8_t *arg)
{
	if (*arg != REG)
		return (FALSE);
	*arg = vm->arena[get_new_pos(car->position, car->step)] - 1;
	car->step++;
	if (*arg >= 0 && *arg < REG_NUMBER)
		return (TRUE);
	else
		return (FALSE);
}

void 			op_sti(t_vm *vm, t_car *car)
{
	int8_t	first;
	int8_t	second;
	int8_t	third;
	int32_t second_val;
	int32_t third_val;
	
	first = determine_arg(vm->arena[(car->position + OP_BYTE) % MEM_SIZE], 0);
	second = determine_arg(vm->arena[(car->position + OP_BYTE) % MEM_SIZE], 1);
	third = determine_arg(vm->arena[(car->position + OP_BYTE) % MEM_SIZE], 2);
	car->step = OP_BYTE + ARG_CHECK;
	if (first != 0 && second != 0 && third != 0)
		if (check_reg(vm, car, &first))
			if (get_arg_dir_two(vm, car, second, &second_val))
				if (get_arg_dir_two(vm, car, third, &third_val))
					write_reg_to_arena(vm, car->registers[first], get_new_pos
								(car->position, (second_val + third_val) % IDX_MOD));
	car->position = get_new_pos(car->position, car->step);
	car->code = vm->arena[car->position] - 1;
	if (car->code >= 0 && car->code < 16)
		car->cycle_to_action = vm->operations.op_cycles[car->code] - 1;
	car->step = 0;
}

