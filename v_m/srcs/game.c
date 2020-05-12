
#include "game.h"

void			cycle_of_game(t_vm *vm)
{
	t_bool		flag_of_end;
	t_car		*tmp;

	flag_of_end = FALSE;
	vm->dump_value = 2110;
	vm->dump_flag = 1;
	vm->current_cycle = 1;
	while (!flag_of_end)
	{
		tmp = vm->carriages;
		while(tmp)
			tmp = check_caret(vm, tmp);
		if (++vm->current_cycle == vm->dump_value && vm->dump_flag)
			flag_of_end = end_dump(vm->arena);
		else if (++vm->iter >= vm->cycle_to_die && !check_live(vm))
			flag_of_end = end_game();
	}
}
