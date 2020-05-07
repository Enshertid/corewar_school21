/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 15:58:35 by ediego            #+#    #+#             */
/*   Updated: 2020/05/02 16:23:29 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

# define REG 1
# define DIR 2
# define IND 3

void miss_arguments(t_vm *pVm, t_car *pCar, int arg, int arg1, int i);

int			determine_arg(unsigned char byte, int index)
{
	const char pos = 0b11000000;
	byte = (byte << (index << 1));
	byte = (byte & pos);
	if (byte == 0b01000000)
		return (REG);
	if (byte == 0b10000000)
		return (DIR);
	if (byte == 0b11000000)
		return (IND);
	else
		return(-1);
}

unsigned char		read_reg_arg(t_vm *vm, int position)
{
	unsigned char		value;
	
	value = vm->arena[position];
	return (value);
}

//int16_t				read_ind_arg(t_vm *vm, int position)
//{
//	int16_t			value;
//
//	(*(char))
//}

static t_bool		reg_reg(t_vm *vm, t_car *car)
{
	int32_t second_index;
	int32_t first_index;
	
	second_index = vm->arena[(car->position + ARG_CHECK + REG * 2) % MEM_SIZE];
	first_index = vm->arena[(car->position + ARG_CHECK + REG) % MEM_SIZE];
	if (first_index >= 1 && first_index < REG_NUMBER &&
								second_index >= 1 && second_index < REG_NUMBER)
		car->registers[first_index] = car->registers[second_index];
	return (TRUE);
}

static t_bool		reg_ind(t_vm *vm, t_car *car)
{
	return (0);
}
void miss_arguments(t_vm *pVm, t_car *pCar, int arg, int arg1, int i)
{

}

void		op_st(t_vm *vm, t_car *car)
{
	char	code_arg;
	int		first_arg, second_arg;
	t_bool	done;
	
	done = FALSE;
	code_arg = vm->arena[(car->position + 1) % MEM_SIZE];
	first_arg = determine_arg(code_arg, 0);
	second_arg = determine_arg(code_arg, 1);
	if (first_arg == REG && second_arg == REG)
		done = reg_reg(vm, car);
	else if (first_arg == REG && second_arg == IND)
		done = reg_ind(vm, car);
	else
		miss_arguments(vm, car, first_arg, second_arg, 0);
}
