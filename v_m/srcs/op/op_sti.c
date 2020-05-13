/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 13:30:32 by ediego            #+#    #+#             */
/*   Updated: 2020/05/13 15:30:57 by ediego           ###   ########.fr       */
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
	int8_t	sec;
	int8_t	third;
	int32_t second_val;
	int32_t third_val;

	printf("STI(%d): Cycle = %ld  POS = %d ", car->id, vm->current_cycle, car->position);
	first = determine_arg(vm->arena[get_new_pos(car->position, car->step)], 0);
	sec = determine_arg(vm->arena[get_new_pos(car->position, car->step)], 1);
	third = determine_arg(vm->arena[get_new_pos(car->position, car->step)], 2);
	car->step += ARG_CHECK;
	if (first != 0 && sec != 0 && third != 0)
		if (check_reg(vm, car, &first))
			if (get_arg_dir_two(vm, car, sec, &second_val))
				if (get_arg_dir_two(vm, car, third, &third_val))
					write_reg_to_arena(vm, car->registers[first], get_new_pos
								(car->position, (second_val + third_val) % IDX_MOD));
	car->position = get_new_pos(car->position, car->step);
	car->code = read_byte(vm, car->position) - 1;
	printf(" END pos = %d\n", car->position);
	if (car->code >= 0 && car->code < OP_NUM)
		car->cycle_to_action = vm->operations.op_cycles[car->code];
	car->step = OP_BYTE;
}

