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
		reg = read_reg(vm, get_new_pos(car->position, car->step)) - 1;
		if (reg >= 0 && reg < 16)
		{
			car->registers[reg] = result;
			if (!result)
				car->carry = TRUE;
			else
				car->carry = FALSE;
		}
	}
}

t_bool		get_arg(t_vm *vm, t_car *car, int8_t sw_arg, int32_t *arg)
{
	if (sw_arg == REG)
	{
		*arg = read_reg(vm, get_new_pos(car->position, car->step)) - 1;
		if (*arg >= 0 && *arg < 16)
			return (FALSE);
	}
	else if (sw_arg == IND)
		*arg = read_dir(vm, read_ind(vm, get_new_pos(car->position, car->step)));
	else if (sw_arg == DIR)
		*arg = read_dir(vm, get_new_pos(car->position, car->step));
	else
		return (FALSE);
	car->step += sw_arg;
	return (TRUE);
}