//
// Created by Daniil&Ekaterina Naumenko on 05/05/2020.
//
#include "game.h"

t_bool			check_live(t_vm *vm)
{
	t_car *tmp;
	
	tmp = vm->carriages;
	while (tmp)
		tmp = try_to_kill_the_carret(&vm->carriages, tmp, vm->cycle_to_die);
	vm->iter = 0;
	return (vm->carriages ? TRUE : FALSE);
}

t_car			*check_caret(t_vm *vm, t_car *caret, t_op op)
{
	if (!caret->cycle_to_action)
	{
		caret->code = vm->arena[caret->position];
		if (caret->code >= 0 && caret->code < 16)
			caret->cycle_to_action = vm->operations.op_cycles[caret->code];
		else
			caret->position++;
	}
	else
	{
		caret->cycle_to_action--;
		if (!caret->cycle_to_action)
			vm->operations.func[caret->code](vm, caret);
	}
	return(caret->next);
}