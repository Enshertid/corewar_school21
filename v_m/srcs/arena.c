/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 18:32:44 by ediego            #+#    #+#             */
/*   Updated: 2020/04/30 15:21:40 by ediego           ###   ########.fr       */
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

t_car		*new_carriage(t_car *current)
{
	t_car *new;
	t_car *iterator;
	int i;

	i = 0;
	iterator = current;
	new = ft_calloc(1 ,sizeof(t_car));
	// ft_memset(new, 0, sizeof(t_car));
	while (iterator)
	{
		i++;
		iterator=iterator->next;
	}
	new->id = i;
	new->next = current;
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
		new->registers[0] = - (i + 1);
		new->position = ((VM_SIZE)/data->players.iter) * i;
		// new->code = vm->arena[new->position];
		vm->carriages = new;
	}
}

void		init_vm_arena(t_vm *vm, t_data *data)
{
	// ft_memset(vm->arena, 0, VM_SIZE);
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->last_live_id = data->players.iter;
	copy_excode(vm, data);
}

void		run_carriages(t_vm *vm, int cycle)
{
	t_car *iter;

	iter = vm->carriages;
	while (iter)
	{
		if (cycle == 0)
			iter->code = vm->arena[iter->position];
		if (!iter->cycle_to_action && iter->code >= 1 && iter->code <= 16)
		{
			iter->code = vm->arena[iter->position];
			iter->cycle_to_action = GET_C[iter->code];
			iter->cycle_to_action -= 1;
			iter->position = VM_SIZE;
			if (iter->code >= 1 && iter->code <= 16)
				printf("Code %d = %d cycle to action\n", iter->code, iter->cycle_to_action);
		}
		else
		{
			iter->cycle_to_action -= 1;
		}
		iter = iter->next;
	}
}

void		run_game(t_vm *vm)
{
	int cycle;

	cycle = 0;
	while (cycle < 1000)
	{
		run_carriages(vm, cycle);
		cycle++;
	}
}

void	 	init_vm(t_vm *vm, t_data *data)
{
	init_vm_arena(vm, data);
	init_carriages(vm, data);
	// init_ops(vm);
	run_game(vm);

	print_arena(vm->arena, VM_SIZE);
	// printf("%d\n", vm->carriages->code);
}
