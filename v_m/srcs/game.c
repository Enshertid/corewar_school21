#include "corewar.h"

t_bool			end_dump(char *arena)
{
	write(1, "end bcs dump flag used\n", 23);
	print_arena(arena, VM_SIZE);
	return (TRUE);
}

t_bool			end_game()
{
	write(1, "game has been end and the winner is bla-bla-bla\n", 49);
	return (TRUE);
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
