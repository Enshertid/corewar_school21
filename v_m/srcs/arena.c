/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 18:32:44 by ediego            #+#    #+#             */
/*   Updated: 2020/05/02 19:03:05 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>

void		print_arena(const void *arena, size_t size)
{
	size_t			i;
	size_t 			j;
	unsigned char	*p;
	char 			*str;

	str = "0123456789abcdef";
	p = (unsigned char *)arena;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < 64 && i + j < size)
		{
			write(1, &str[(*(p + i + j)/16) % 16], 1);
			write(1, &str[*(p + i + j) % 16], 1);
			// if (j % 2) // comment me!
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i += 64;
	}
}

void		copy_excode(t_vm *vm, t_data *data)
{
	int i;
	int pos;

	i = 0;
	while (i < (int)data->players.iter)
	{
		pos = ((VM_SIZE)/data->players.iter) * i;
		ft_memcpy(&(vm->arena[pos]), data->players.arr[i]->ex_code, data->players.arr[i]->ex_size);
		i++;
	}
}

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

void		init_carriages(t_vm *vm, t_data *data)
{
	int i;
	t_car *new;

	i = -1;
	while (++i < (int)data->players.iter)
	{
		new = new_carriage(vm->carriages);
		new->registers[0] = (i + 1);
		new->position = ((VM_SIZE)/data->players.iter) * i;
		vm->carriages = new;
	}
}

void		init_vm_arena(t_vm *vm, t_data *data)
{
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->last_live_id = data->players.iter;
	copy_excode(vm, data);
}



void	 	init_vm(t_vm *vm, t_data *data)
{
	init_vm_arena(vm, data);
	init_carriages(vm, data);
	// print_arena(vm->arena, VM_SIZE);
}
