/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 13:30:32 by ediego            #+#    #+#             */
/*   Updated: 2020/05/19 20:52:30 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

static t_bool	get_third(t_vm *vm, t_car *car, int8_t *sw_arg, int32_t *value)
{
	if (*sw_arg != REG && *sw_arg != DIR)
		return (FALSE);
	if (*sw_arg == REG)
	{
		*value = read_byte(vm, get_new_pos(car->position, car->step)) - 1;
		if (*value < 0 || *value >= REG_NUMBER)
			return (FALSE);
		*value = car->registers[*value];
	}
	else
	{
		*value = read_two_bytes(vm, get_new_pos(car->position, car->step));
		*sw_arg = DIR / 2;
	}
	car->step += *sw_arg;
	return (TRUE);
}

static t_bool 	check_reg(t_vm *vm, t_car *car, int8_t arg, int8_t *val)
{
	if (arg != REG)
		return (FALSE);
	*val = read_byte(vm, get_new_pos(car->position, car->step)) - 1;
	car->step += REG;
	if (*val >= 0 && *val < REG_NUMBER)
		return (TRUE);
	else
		return (FALSE);
}

void			op_sti(t_vm *vm, t_car *car)
{
	int8_t		first;
	int8_t		sec;
	int8_t		third;
	int8_t		first_val;
	int32_t		sec_val;
	int32_t		third_val;

	if (vm->debug)
		printf("STI(%d): Cycle = %ld POS = %d", car->id, vm->current_cycle, car->position);
	first = determine_arg(vm->arena[get_new_pos(car->position, car->step)], 0);
	sec = determine_arg(vm->arena[get_new_pos(car->position, car->step)], 1);
	third = determine_arg(vm->arena[get_new_pos(car->position, car->step)], 2);
	if (vm->debug)
		printf(" first %d, second %d, third %d", first, sec, third);
	car->step += ARG_CHECK;
	if (first != 0 && sec != 0 && third != 0)
		if (check_reg(vm, car, first, &first_val))
			if (get_arg_dir_two(vm, car, &sec, &sec_val))
				if (get_third(vm, car, &third, &third_val))
					write_reg_to_arena(vm, car->registers[first_val],
					get_new_pos(car->position,get_idx(sec_val + third_val)));
	if (third == DIR)
		third = DIR / 2;
	if (sec == DIR)
	{
		sec = DIR / 2;
	}
	if (vm->debug)
		printf(" write to = %d ", get_new_pos(car->position,get_idx(sec_val + third_val)));
	change_position(vm, car, OP_BYTE + ARG_CHECK + first + sec + third);
	if (vm->debug)
		printf(" End = %d \n", first, sec, third, car->position);
}
