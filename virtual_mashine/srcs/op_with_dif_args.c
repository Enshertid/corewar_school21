/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_with_dif_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:22:36 by ediego            #+#    #+#             */
/*   Updated: 2020/05/26 12:22:37 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

bool			invalid_reg(t_vm *vm, t_car *car, int8_t args, int num)
{
	int8_t		reg;
	int32_t		pos;

	pos = (get_pos(car, get_arg_step(args, num, DIR_SIZE / 2)));
	reg = (vm->arena[pos]);
	if (reg < 1 || reg > REG_NUMBER)
		return (true);
	car->step += 1;
	return (false);
}

void			set_reg(t_car *car, int8_t reg, int32_t value, bool edit_carry)
{
	if (edit_carry)
		car->carry = value ? false : true;
	car->registers[--reg] = value;
}

int				get_pos(t_car *car, int pos)
{
	int32_t		new_pos;

	new_pos = car->position + pos;
	if (new_pos >= MEM_SIZE || -new_pos >= MEM_SIZE)
		new_pos %= MEM_SIZE;
	if (new_pos < 0)
		new_pos += MEM_SIZE;
	return (new_pos);
}

int				get_idx(int value)
{
	return (value % IDX_MOD);
}

void			change_position(t_car *car, t_arg *args, int8_t type)
{
	int32_t		step;

	step = OP_BYTE + ARG_CHECK;
	if (type == ONE)
		step += args->first;
	else if (type == TWO)
		step += args->first + args->sec_d;
	else
		step += args->first + args->sec_d + args->third;
	car->position = get_pos(car, step);
	car->step = OP_BYTE;
}
