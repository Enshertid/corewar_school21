//
// Created by Daniil&Ekaterina Naumenko on 05/05/2020.
//

#include "carriages.h"

t_car		*create_caret(int position_on_arena, int id)
{
	t_car		*node;
	
	node = ft_calloc(1, sizeof(t_car));
	node->position = position_on_arena;
	node->id = id;
	node->num_of_carets = 1;
	node->registers[0] = -id;
	return (node);
}

t_car		*copy_caret(t_car *parent, int32_t position, int32_t id)
{
	t_car		*node;
	
	node = ft_calloc(1, sizeof(t_car));
	ft_memcpy(node, parent, sizeof(t_car));
	node->position = position;
	node->id = id;
	return(node);
}

void		add_caret(t_car **head, t_car *new_node)
{
	if (*head)
	{
		(*head)->prev = new_node;
		new_node->next = *head;
		*head = new_node;
		(*head)->num_of_carets = (*head)->next->num_of_carets + 1;
	}
	else
	{
		*head = new_node;
		(*head)->num_of_carets = 1;
	}
}