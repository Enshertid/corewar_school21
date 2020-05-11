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

static void		reg_reg(t_vm *vm, t_car *car)
{
	int32_t second_index;
	int32_t first_index;
	
	second_index =
			read_byte(vm, (car->position + ARG_CHECK + REG * 2) % MEM_SIZE);
	first_index =
			read_byte(vm, (car->position + ARG_CHECK + REG) % MEM_SIZE);
	if (first_index >= 1 && first_index < REG_NUMBER &&
								second_index >= 1 && second_index < REG_NUMBER)
		car->registers[first_index] = car->registers[second_index];
}

static void		reg_ind(t_vm *vm, t_car *car)
{
	int16_t		ind_arg;
	int8_t		first_arg;
	
	first_arg = read_byte(vm, (car->position + 2) % MEM_SIZE) - 1;
	ind_arg = (read_four_bytes(vm, (car->position + 3) % MEM_SIZE) % IDX_MOD);
	if (first_arg >= 0 && first_arg < REG_NUMBER)
		write_reg_to_arena(vm, car->registers[first_arg],
										get_new_pos(car->position, ind_arg));
}

void		op_st(t_vm *vm, t_car *car)
{
	char		code_arg;
	int			first_arg, second_arg;

	code_arg = vm->arena[(car->position + 1) % MEM_SIZE];
	first_arg = determine_arg(code_arg, 0);
	second_arg = determine_arg(code_arg, 1);
	if (first_arg == REG && second_arg == REG)
		reg_reg(vm, car);
	else if (first_arg == REG && second_arg == IND)
		reg_ind(vm, car);
	car->position = (car->position + first_arg + second_arg + 2) % MEM_SIZE;
	car->code = vm->arena[car->position] - 1;
	if (car->code >= 0 && car->code < 16)
		car->cycle_to_action = vm->operations.op_cycles[car->code] - 1;
}
