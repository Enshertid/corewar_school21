//
// Created by Daniil&Ekaterina Naumenko on 05/05/2020.
//

#include "corewar.h"
#include "carriages.h"

static void		init_carriages(t_vm *vm, int iter)
{
	int i;
	t_car *list;
	
	i = 0;
	list = create_caret(0, 1);
	while (++i < iter)
	{
		add_caret(&list, create_caret((MEM_SIZE / iter) * i, i + 1));
		vm->id_cars++;
	}
	vm->carriages = list;
}

static void		init_vm_arena(t_vm *vm, t_players *players)
{
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->last_live_id = players->iter;
	vm->players = players;
	copy_excode(vm, players);
}

static void	 	init_vm(t_vm *vm, t_data *data)
{
	init_vm_arena(vm, &data->players);
	init_carriages(vm, data->players.iter);
}

static void			init_players(t_players *players)
{
	players->arr = ft_calloc(MAX_PLAYERS, sizeof(t_player*));
	players->size = MAX_PLAYERS;
}

void			init_data(t_data *data, int ac, char **av)
{
	ft_memset(data, 0, sizeof(t_data));
	set_array_of_operations(data);
	set_array_of_cycles_to_op(data);
	init_players(&data->players);
	parsing(&data->players, ac, av);
	init_vm(&data->vm, data);
}