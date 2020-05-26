/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:16:36 by ediego            #+#    #+#             */
/*   Updated: 2020/05/26 12:16:38 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

static void			dir_reg(t_vm *vm, t_car *car)
{
	int32_t			value;
	int8_t			reg;

	value = read_four_bytes(vm, (car->position + 2) % MEM_SIZE);
	reg = vm->arena[(car->position + 6) % MEM_SIZE];
	if (reg > 0 && reg <= REG_NUMBER)
		set_reg(car, reg, value, 1);
}

static void			ind_reg(t_vm *vm, t_car *car)
{
	int				ind;
	int32_t			value;
	int8_t			reg;

	ind = get_pos(car, (read_two_bytes(vm, (car->position + 2) % MEM_SIZE)));
	value = read_two_bytes(vm, ind);
	reg = vm->arena[(car->position + 4) % MEM_SIZE];
	if (reg > 0 && reg <= REG_NUMBER)
		set_reg(car, reg, value, 1);
}

void				op_lld(t_vm *vm, t_car *car, t_arg *arg)
{
	int8_t			args;

	(void)arg->first;
	args = vm->arena[(car->position + 1) % MEM_SIZE];
	if (check_arg(args) == DIR_CODE && check_arg(args << 2) == REG_CODE)
		dir_reg(vm, car);
	else if (check_arg(args) == IND_CODE && check_arg(args << 2) == REG_CODE)
		ind_reg(vm, car);
	car->position = get_pos(car, get_arg_step(args, 2, DIR_SIZE));
}
