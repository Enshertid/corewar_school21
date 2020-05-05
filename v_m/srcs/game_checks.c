//
// Created by Daniil&Ekaterina Naumenko on 05/05/2020.
//
#include "game.h"

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

t_car			*check_caret(t_car *caret, t_op op)
{
	t_bool flag_of_killed;
	
	flag_of_killed = FALSE;
	if (caret->cycle_to_action)
		caret->cycle_to_action--;
	if (!caret->cycle_to_action)
		flag_of_killed == use_op(caret, op);
	return (flag_of_killed ? caret : caret->next);
}