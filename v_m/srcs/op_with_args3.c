/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_with_args3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 00:47:38 by ediego            #+#    #+#             */
/*   Updated: 2020/05/21 13:29:54 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

int 		mget_pos(t_car *car, int pos)
{
	int32_t		new_pos;
	
	new_pos = car->position + pos;
	if (new_pos >= MEM_SIZE || -new_pos >= MEM_SIZE)
		new_pos %= MEM_SIZE;
	if (new_pos < 0)
		new_pos += MEM_SIZE;
	return(new_pos);
}

int 		get_idx(int value)
{
	return(value % IDX_MOD);
}

bool 		invalid_reg(t_vm *vm, t_car *car, int8_t args, int num)
{
	int8_t reg;
	int32_t pos;

	pos = (get_pos(car, get_arg_step(args, num, DIR_SIZE/2)));
	reg = (vm->arena[pos]);
	if (reg < 1 || reg > REG_NUMBER)
		return(true);
	car->step += 1;
	return(false);
}

void 		set_reg(t_car *car, int8_t reg, int32_t value, bool edit_carry)
{
	if (edit_carry)
	{
		if (!value)
			car->carry = 1;
		else
			car->carry = 0;
	}
	car->registers[--reg] = value;
}
