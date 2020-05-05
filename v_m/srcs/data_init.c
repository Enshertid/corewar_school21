//
// Created by Daniil&Ekaterina Naumenko on 05/05/2020.
//

#include "corewar.h"
#include "carriages.h"

static void		init_carriages(t_vm *vm, int iter)
{
	int i;
	t_car *new;
	
	i = -1;
	while (++i < iter)
	{
		new = new_carriage(vm->carriages);
		new->registers[0] = (i + 1);
		new->position = ((VM_SIZE) / iter) * i;
		vm->carriages = new;
	}
}

static void		init_vm_arena(t_vm *vm, t_players *players)
{
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->last_live_id = players->iter;
	copy_excode(vm, players);
}

static void	 	init_vm(t_vm *vm, t_data *data)
{
	init_vm_arena(vm, &data->players);
	init_carriages(vm, data->players.iter);
	// print_arena(vm->arena, VM_SIZE);
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
	init_players(&data->players);
	data->pars.ac = ac;
	data->pars.av = av;
	data->pars.i = 1;
	parsing(&data->pars, &data->players);
	init_vm(&data->vm, data);
}