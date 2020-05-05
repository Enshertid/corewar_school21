//
// Created by Daniil&Ekaterina Naumenko on 05/05/2020.
//

#include "carriages.h"

t_car		*new_carriage(t_car *head)
{
	t_car *new;
	t_car *iterator;
	int i;
	
	i = 0;
	iterator = head;
	new = ft_calloc(1 ,sizeof(t_car));
	while (iterator)
	{
		i++;
		iterator=iterator->next;
	}
	if (head)
		head->prev = new;
	new->id = i;
	new->next = head;
	return(new);
}