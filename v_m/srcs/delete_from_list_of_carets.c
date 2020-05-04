//
// Created by Daniil&Ekaterina Naumenko on 01/05/2020.
//

#include "corewar.h"

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