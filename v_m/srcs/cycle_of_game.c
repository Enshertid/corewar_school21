#include "corewar.h"

t_bool			end_dump()
{
	write(1, "end bcs dump flag used\n", 23);
	return (TRUE);
}

t_bool			end_game()
{
	write(1, "game has been end and the winner is bla-bla-bla\n", 49);
	return (TRUE);
}

t_car			*check_caret(t_car *caret)
{
	
	return (caret->next);
}

t_car			*kill_the_carret(t_data *data, t_car *cur_car)
{
	if (cur_car->last_live_cycle >= data->vm.cycle_to_die)
	{
		if (!cur_car->next)
			return (delete_from_end(cur_car));
		else if (!cur_car->prev)
			return (delete_from_begin(cur_car));
		else
			return(delete_from_body(cur_car));
	}
	return (cur_car->next);
}

t_bool			check_live(t_data *data)
{
	t_car *tmp;
	
	tmp = data->vm.carriages;
	while (tmp)
		tmp = kill_the_carret(data, tmp);
	data->vm.iter = 0;
	if (!data->vm.carriages)
		return(FALSE);
	else
		return(TRUE);
}

void			cycle_of_game(t_data *data)
{
	t_bool		flag_of_end;
	t_car		*tmp;

	data->vm.iter = 0;
	data->vm.dump_count = 0;
	flag_of_end = FALSE;
	while (!flag_of_end)
	{
		tmp = data->vm.carriages;
		while(tmp)
			tmp = check_caret(tmp);
		if (++data->vm.dump_count == data->vm.dump_value)
			flag_of_end = end_dump();
		else if (++data->vm.iter >= data->vm.cycle_to_die && !check_live(data))
			flag_of_end = end_game();
	}
}

