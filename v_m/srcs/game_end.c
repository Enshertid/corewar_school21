//
// Created by Daniil&Ekaterina Naumenko on 05/05/2020.
//

#include "game.h"

t_player		*define_winner(t_players *players)
{
	int8_t		iter;
	int8_t		winner_id;
	size_t		live_cycle;
	
	iter = 0;
	winner_id = iter;
	live_cycle = players->arr[iter]->live;
	while (++iter < players->size)
	{
		if (live_cycle < players->arr[iter]->live)
		{
			winner_id = iter;
			live_cycle = players->arr[iter]->live;
		}
	}
	return(players->arr[winner_id]);
}

bool			end_dump(t_vm *vm)
{
	t_car *tmp;
	
	print_arena(vm->arena, MEM_SIZE);
	tmp = vm->carriages;
	while (tmp)
		tmp = delete_from_begin(&vm->carriages, tmp);
	return (true);
}

bool			end_game(t_players *players)
{
	t_player	*winner;
	
	winner = define_winner(players);
	write(1,"Contestant ", 11);
	winner->id += '0';
	write(1, &winner->id, 1);
	write(1, ", \"", 3);
	write(1, winner->name, ft_strlen(winner->name));
	write(1, "\", has won!\n", 12);
	return (true);
}
