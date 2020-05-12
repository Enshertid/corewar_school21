//
// Created by Daniil&Ekaterina Naumenko on 05/05/2020.
//

#include "corewar.h"
#include "pars.h"
#include "vm.h"
#include "carriages.h"
#include "op.h"
#include "libft.h"
#include "players.h"
#include "operations.h"

static void		init_carriages(t_vm *vm, int iter)
{
	int i;
	t_car *list;
	
	i = 0;
	list = create_caret(0, 1);
	vm->id_cars++;
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
	copy_excode(vm, players);
}

static void	 	init_vm(t_vm *vm, t_players *players)
{
	init_vm_arena(vm, players);
	init_carriages(vm, players->size);
	if (players->dump_flag)
	{
		vm->dump_value = players->dump_num;
		vm->dump_flag = TRUE;
	}
}

static void			init_players(t_players *players)
{
	players->arr = ft_calloc(MAX_PLAYERS, sizeof(t_player*));
	players->size = MAX_PLAYERS;
}

void			init_data(t_vm *vm, int ac, char **av)
{
	ft_memset(vm, 0, sizeof(t_vm));
	set_array_of_operations(vm);
	set_array_of_cycles_to_op(vm);
	init_players(&vm->players);
	parsing(&vm->players, ac, av);
	init_vm(vm, &vm->players);
}