//
// Created by Daniil&Ekaterina Naumenko on 08/05/2020.
//

#include "operations.h"
#include "vm.h"

void			use_args(t_vm *vm, t_car *car, int32_t result,
								int8_t third)
{
	int32_t reg;
	
	if (third == REG)
	{
		reg = read_byte(vm, get_new_pos(car->position, car->step)) - 1;
		if (reg >= 0 && reg < REG_NUMBER)
		{
			car->registers[reg] = result;
			if (!result)
				car->carry = TRUE;
			else
				car->carry = FALSE;
		}
	}
}

t_bool 		get_arg_dir_two(t_vm *vm, t_car *car, int8_t *sw_arg, int32_t *arg)
{
	if (*sw_arg == REG)
	{
		*arg = read_byte(vm, get_new_pos(car->position, car->step)) - 1;
		if (*arg < 0 && *arg >= REG_NUMBER)
			return (FALSE);
		*arg = car->registers[*arg];
	}
	else if (*sw_arg == IND)
		*arg = read_four_bytes(vm, get_new_pos(car->position,
		read_two_bytes(vm, get_new_pos(car->position, car->step)) % IDX_MOD));
	else if (*sw_arg == DIR)
	{
		*arg = read_two_bytes(vm, get_new_pos(car->position, car->step));
		*sw_arg = DIR / 2;
	}
	else
		return (FALSE);
	car->step += *sw_arg;
	return (TRUE);
}

t_bool		get_arg_dir_four(t_vm *vm, t_car *car, int8_t sw_arg, int32_t *arg)
{
	if (sw_arg == REG)
	{
		*arg = read_byte(vm, get_new_pos(car->position, car->step)) - 1;
		if (*arg >= 0 && *arg < REG_NUMBER)
			*arg = car->registers[*arg];
		else
			return (FALSE);
	}
	else if (sw_arg == IND)
		*arg = read_four_bytes(vm, get_new_pos(car->position,
		read_two_bytes(vm, get_new_pos(car->position, car->step)) % IDX_MOD));
	else if (sw_arg == DIR)
		*arg = read_four_bytes(vm, get_new_pos(car->position, car->step));
	else
		return (FALSE);
	car->step += sw_arg;
	return (TRUE);
}

void		change_position(t_vm *vm, t_car *car, int32_t step)
{
	car->position = get_new_pos(car->position, step);
	car->code = read_byte(vm, car->position) - 1;
	if (car->code >= 0 && car->code < OP_NUM)
		car->cycle_to_action = vm->operations.op_cycles[car->code];
	car->step = OP_BYTE;
}

void		write_to_reg_a_s(t_vm *vm, t_car *car, int8_t type)
{
	int8_t		first;
	int8_t		second;
	int8_t		third;
	int32_t		res;
	
	car->step += ARG_CHECK;
	first = read_byte(vm, get_new_pos(car->position, car->step)) - 1;
	car->step += REG;
	second = read_byte(vm, get_new_pos(car->position, car->step)) - 1;
	car->step += REG;
	third = read_byte(vm, get_new_pos(car->position, car->step)) - 1;
	if (first >= 0 && first < REG_NUMBER && second >= 0 && second <
				REG_NUMBER && third >= 0 && third < REG_NUMBER)
	{
		if (type == PLUS)
			res = car->registers[first] + car->registers[second];
		else
			res = car->registers[first] - car->registers[second];
		car->registers[third] = res;
		if (!car->registers[third])
			car->carry = TRUE;
		else
			car->carry = FALSE;
	}
}