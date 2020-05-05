//
// Created by Daniil&Ekaterina Naumenko on 05/05/2020.
//
#include "game.h"

t_bool			use_op(t_car *caret, t_op op)
{
	if (caret->code >)
}

t_bool			check_live(t_vm *vm)
{
	t_car *tmp;
	
	tmp = vm->carriages;
	while (tmp)
		tmp = try_to_kill_the_carret(tmp, vm->cycle_to_die);
	vm->iter = 0;
	if (!vm->carriages)
		return(FALSE);
	else
		return(TRUE);
}

t_car			*check_caret(t_vm *vm, t_car *caret, t_op op)
{
	if (!caret->cycle_to_action)
	{
		caret->code = vm->arena[caret->position];
		if (caret->code > 0 && caret->code < 17)
			caret->cycle_to_action = vm->operations.op_cycles[caret->code];
		else
			caret->position++;
	}
	caret->cycle_to_action--;
	if (!caret->cycle_to_action)
		use_operation(caret, op);
	return(caret->next);
}