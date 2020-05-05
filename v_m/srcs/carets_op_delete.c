//
// Created by Daniil&Ekaterina Naumenko on 01/05/2020.
//

#include "carriages.h"

t_car			*delete_from_end(t_car **head, t_car *cur_car)
{
	if (cur_car->prev)
		cur_car->prev->next = NULL;
	cur_car->prev = NULL;
	free(cur_car);
	(*head)->num_of_carets--;
	return (NULL);
}

t_car			*delete_from_begin(t_car **head, t_car *cur_car)
{
	cur_car->next->num_of_carets = --cur_car->num_of_carets;
	cur_car = cur_car->next;
	cur_car->prev->next = NULL;
	free(cur_car->prev);
	cur_car->prev = NULL;
	*head = cur_car;
	return (cur_car);
}

t_car			*delete_from_body(t_car **head, t_car *cur_car)
{
	t_car			*tmp;

	tmp = cur_car;
	cur_car = cur_car->next;
	tmp->next->prev = tmp->prev;
	tmp->prev->next = tmp->next;
	tmp->prev = NULL;
	tmp->next = NULL;
	free(tmp);
	(*head)->num_of_carets--;
	return (cur_car);
}

t_car			*try_to_kill_the_carret(t_car **head, t_car *cur_car,
													int cycle_to_die)
{
	if (cur_car->last_live_cycle >= cycle_to_die)
	{
		if (!cur_car->next)
			return (delete_from_end(head, cur_car));
		else if (!cur_car->prev)
			return (delete_from_begin(head, cur_car));
		else
			return (delete_from_body(head, cur_car));
	}
	return (cur_car->next);
}
