/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 15:58:35 by ediego            #+#    #+#             */
/*   Updated: 2020/05/10 20:54:36 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

static t_bool		get_second(t_vm *vm, t_car *car, int8_t type, int16_t *arg)
{
	if (type != REG && type != IND)
		return (FALSE);
	if (type == REG)
	{
		*arg = read_byte(vm, get_new_pos(car->position, car->step)) - 1;
		if (*arg < 0 || *arg >= REG_NUMBER)
			return (FALSE);
	}
	else
		*arg = read_two_bytes(vm, get_new_pos(car->position, car->step)) % IDX_MOD;
	car->step += type;
	return (TRUE);
}

static t_bool		get_first(t_vm *vm, t_car *car, int8_t byte, int8_t *arg)
{
	if (byte != REG)
		return (FALSE);
	*arg = read_byte(vm, get_new_pos(car->position, car->step)) - 1;
	car->step += REG;
	if (*arg >= 0 && *arg < REG_NUMBER)
		return (TRUE);
	else
		return (FALSE);
}

void		op_st(t_vm *vm, t_car *car)
{
	int8_t		first;
	int8_t 		sec;
	int8_t		first_value;
	int16_t		second_value;
	
	first = determine_arg(vm->arena[get_new_pos(car->position, car->step)], 0);
	sec = determine_arg(vm->arena[get_new_pos(car->position, car->step)], 1);
	car->step += ARG_CHECK;
	if (get_first(vm, car, first, &first_value))
	{
		if (get_second(vm, car, sec, &second_value))
		{
			if (sec == REG)
				car->registers[second_value] = car->registers[first_value];
			else
				write_reg_to_arena(vm, car->registers[first_value],
								   get_new_pos(car->position, second_value));
		}
	}
	car->position = get_new_pos(car->position, car->step);
	car->code = read_byte(vm, car->position) - 1;
	if (car->code >= 0 && car->code < OP_NUM)
		car->cycle_to_action = vm->operations.op_cycles[car->code];
	car->step = OP_BYTE;
}
