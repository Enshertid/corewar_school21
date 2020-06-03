/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 20:54:54 by user              #+#    #+#             */
/*   Updated: 2020/06/03 20:54:55 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void			copy_excode(t_vm *vm, t_players *players)
{
	int				i;
	int				pos;

	i = 0;
	while (i < (int)players->iter)
	{
		pos = ((MEM_SIZE) / (int)players->iter) * i;
		ft_memcpy(&(vm->arena[pos]), players->arr[i]->ex_code,
											players->arr[i]->ex_size);
		i++;
	}
}

static void			init_carriages(t_vm *vm, int iter)
{
	int				i;
	t_car			*list;

	i = 0;
	list = create_caret(0, 1);
	vm->id_cars++;
	vm->num_of_car = 1;
	while (++i < iter)
	{
		add_caret(&list, create_caret((MEM_SIZE / iter) * i, i + 1));
		vm->id_cars++;
		vm->num_of_car++;
	}
	vm->carriages = list;
}

static void			init_vm_arena(t_vm *vm, t_players *players)
{
	vm->cycle_to_die = CYCLE_TO_DIE;
	copy_excode(vm, players);
}

void				init_vm(t_vm *vm, t_players *players)
{
	init_vm_arena(vm, players);
	init_carriages(vm, players->size);
	vm->dump_value = players->dump_num >= 0 ? players->dump_num : -1;
	vm->dump_size = players->dump_size;
	vm->aff = players->aff;
	vm->winner_id = players->size;
}
