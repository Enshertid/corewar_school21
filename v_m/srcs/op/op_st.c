/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:17:54 by ediego            #+#    #+#             */
/*   Updated: 2020/05/26 12:17:55 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

static bool			get_second(t_vm *vm, t_car *car, int8_t type, int32_t *arg)
{
	if (type != REG && type != IND)
		return (false);
	if (type == REG)
	{
		*arg = read_byte(vm, get_pos(car, car->step)) - 1;
		if (*arg < 0 || *arg >= REG_NUMBER)
			return (false);
	}
	else
		*arg = read_two_bytes(vm, get_pos(car, car->step)) % IDX_MOD;
	car->step += type;
	return (true);
}

void				op_st(t_vm *vm, t_car *car, t_arg *arg)
{
	int32_t			reg;
	int32_t			pos;

	arg->first = determine_arg(vm->arena[get_pos(car, car->step)], 0);
	arg->sec_d = determine_arg(vm->arena[get_pos(car, car->step)], 1);
	car->step += ARG_CHECK;
	if (check_reg(vm, car, arg->first, &reg) &&
		get_second(vm, car, arg->sec_d, &arg->sec_d_val))
	{
		if (arg->sec_d == REG)
			car->registers[arg->sec_d_val] = car->registers[reg];
		else
		{
			pos = get_pos(car, arg->sec_d_val);
			write_reg_to_arena(vm, car->registers[reg], pos);
		}
	}
	change_position(car, arg, TWO);
}
