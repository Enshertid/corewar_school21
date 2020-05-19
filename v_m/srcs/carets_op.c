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
	node->registers[0] = -id;
	node->step = OP_BYTE;
	return (node);
}

t_car		*copy_caret(t_car *parent, int32_t position, int32_t id)
{
	t_car		*node;
	int i;
	
	node = ft_calloc(1, sizeof(t_car));
	i = 0;
	ft_memcpy(node,parent, sizeof(t_car));
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
		new_node->prev = NULL;
		*head = new_node;
	}
	else
		*head = new_node;
}