//
// Created by Daniil&Ekaterina Naumenko on 01/05/2020.
//

#include "carriages.h"

t_car			*delete_from_end(t_car *cur_car)
{
	if (cur_car->prev)
		cur_car->prev->next = NULL;
	cur_car->prev = NULL;
	free(cur_car);
	return (NULL);
}

t_car			*delete_from_begin(t_car *cur_car)
{
	cur_car = cur_car->next;
	cur_car->prev->next = NULL;
	free(cur_car->prev);
	cur_car->prev = NULL;
	return (cur_car);
}

t_car			*delete_from_body(t_car *cur_car)
{
	t_car			*tmp;

	tmp = cur_car;
	cur_car = cur_car->next;
	tmp->next->prev = tmp->prev;
	tmp->prev->next = tmp->next;
	tmp->prev = NULL;
	tmp->next = NULL;
	free(tmp);
	return (cur_car);
}

t_car			*try_to_kill_the_carret(t_car *cur_car, int cycle_to_die)
{
	if (cur_car->last_live_cycle >= cycle_to_die)
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
