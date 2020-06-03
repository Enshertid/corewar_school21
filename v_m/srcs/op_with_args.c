/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_with_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:22:05 by ediego            #+#    #+#             */
/*   Updated: 2020/05/26 12:22:07 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

int						determine_arg(unsigned char byte, unsigned int index)
{
	const unsigned char	pos = 0b11000000;

	byte = (byte << (index << 1));
	byte = (byte & pos);
	if (byte == 0b01000000)
		return (REG);
	if (byte == 0b10000000)
		return (DIR);
	if (byte == 0b11000000)
		return (IND);
	else
		return (0);
}

unsigned char			read_byte(t_vm *vm, int position)
{
	unsigned char		value;

	value = vm->arena[position];
	return (value);
}

int16_t					read_two_bytes(t_vm *vm, int position)
{
	int16_t				value;

	value = 0;
	*((char*)&value + 1) = vm->arena[position];
	*((char*)&value) = vm->arena[(position + 1) % MEM_SIZE];
	return (value);
}

int32_t					read_four_bytes(t_vm *vm, int position)
{
	int32_t				value;

	value = 0;
	*((char*)&value + 3) = vm->arena[position];
	*((char*)&value + 2) = vm->arena[(position + 1) % MEM_SIZE];
	*((char*)&value + 1) = vm->arena[(position + 2) % MEM_SIZE];
	*((char*)&value) = vm->arena[(position + 3) % MEM_SIZE];
	return (value);
}

void					write_reg_to_arena(t_vm *vm, int32_t value,
																int position)
{
	int8_t				i;

	i = -1;
	while (++i < 4)
		vm->arena[(position + i) % MEM_SIZE] = *((char*)&value + 3 - i);
}
