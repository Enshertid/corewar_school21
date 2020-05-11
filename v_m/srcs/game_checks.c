//
// Created by Daniil&Ekaterina Naumenko on 05/05/2020.
//

#include "game.h"
#include "carriages.h"
#include "stdio.h"

t_bool			check_live(t_vm *vm)
{
	t_car *tmp;
	
	printf("cycles to live==>%d\n", vm->cycle_to_die);
	printf("count live ==> %d\n", vm->count_live);
	tmp = vm->carriages;
	while (tmp)
		tmp = try_to_kill_the_carret(&vm->carriages, tmp, vm->cycle_to_die);
	vm->iter = 0;
	if (vm->count_live >= NBR_LIVE || vm->count_checks >= MAX_CHECKS)
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		vm->count_checks = 0;
	}
	vm->count_checks++;
	vm->count_live = 0;
	return (vm->carriages ? TRUE : FALSE);
}

t_car			*check_caret(t_vm *vm, t_car *caret)
{
	caret->last_live_cycle++;
	if (!caret->cycle_to_action)
	{
		caret->code = vm->arena[caret->position] - 1;
		if (caret->code >= 0 && caret->code < 16)
			caret->cycle_to_action = vm->operations.op_cycles[caret->code] - 1;
		else
			caret->position = (caret->position + 1) % MEM_SIZE;
	}
	else if (!(--caret->cycle_to_action))
	{
		printf("going to operation ==> \n current cycle ==> %d\n", vm->current_cycle);
		vm->operations.func[caret->code](vm, caret);
	}
	return(caret->next);
}