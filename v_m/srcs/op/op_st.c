/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 15:58:35 by ediego            #+#    #+#             */
/*   Updated: 2020/05/17 18:55:24 by ediego           ###   ########.fr       */
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
		*arg = read_two_bytes(vm,
				get_new_pos(car->position, car->step)) % IDX_MOD;
	car->step += type;
	return (TRUE);
}

static t_bool		check_reg(t_vm *vm, t_car *car, int8_t byte, int8_t *arg)
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
	
	printf("ST(%d): Cycle = %ld POS = %d", car->id, vm->current_cycle, car->position);
	first = determine_arg(vm->arena[get_new_pos(car->position, car->step)], 0);
	sec = determine_arg(vm->arena[get_new_pos(car->position, car->step)], 1);
	car->step += ARG_CHECK;
	if (check_reg(vm, car, first, &first_value))
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
	change_position(vm, car, OP_BYTE + ARG_CHECK + first + sec);
	printf(" End = %d\n", car->position);
}
