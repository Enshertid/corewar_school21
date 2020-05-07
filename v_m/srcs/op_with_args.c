//
// Created by Daniil&Ekaterina Naumenko on 07/05/2020.
//

#include "corewar.h"

int			determine_arg(unsigned char byte, unsigned int index)
{
	const unsigned char pos = 0b11000000;
	
	byte = (byte << (index << 1));
	byte = (byte & pos);
	if (byte == 0b01000000)
		return (REG);
	if (byte == 0b10000000)
		return (DIR);
	if (byte == 0b11000000)
		return (IND);
	else
		return(0);
}

unsigned char		read_reg_arg(t_vm *vm, int position)
{
	unsigned char		value;
	
	value = vm->arena[position];
	return (value);
}

int16_t				read_ind_arg(t_vm *vm, int position)
{
	int16_t			value;
	
	*((char*)&value) = vm->arena[position];
	*((char*)&value + 1) = vm->arena[(position + 1) % MEM_SIZE];
	return (value);
}

int32_t				read_dir_arg(t_vm *vm, int position)
{
	int32_t		value;
	
	*((char*)&value) = vm->arena[position];
	*((char*)&value + 1) = vm->arena[(position + 1) % MEM_SIZE];
	*((char*)&value + 2) = vm->arena[(position + 2) % MEM_SIZE];
	*((char*)&value + 3) = vm->arena[(position + 3) % MEM_SIZE];
	return(value);
}

void			write_reg_to_arena(t_vm *vm, int32_t value, int position)
{
	int8_t		i;
	
	i = 0;
	while (i < 4)
	{
		vm->arena[(position + i) % MEM_SIZE] = *((char*)&value + i);
		i++;
	}
}

int32_t			get_new_pos(int32_t position, int32_t step)
{
	position += step;
	if (position < 0)
		return (MEM_SIZE + position);
	else
		return (position % MEM_SIZE);
}