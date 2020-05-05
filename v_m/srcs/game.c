#include "corewar.h"
#include "game.h"

void			cycle_of_game(t_vm *vm)
{
	t_bool		flag_of_end;
	t_car		*tmp;

	flag_of_end = FALSE;
	while (!flag_of_end)
	{
		tmp = vm->carriages;
		while(tmp)
			tmp = check_caret(tmp, vm->operations);
		if (++vm->dump_count == vm->dump_value)
			flag_of_end = end_dump(vm->arena);
		else if (++vm->iter >= vm->cycle_to_die && !check_live(vm))
			flag_of_end = end_game();
	}
}
