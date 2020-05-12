//
// Created by Daniil&Ekaterina Naumenko on 05/05/2020.
//

#include "game.h"

t_player		*define_winner(t_players *players)
{
	int8_t		iter;
	int8_t		winner_id;
	int32_t		live_cycle;
	
	iter = 0;
	winner_id = iter;
	live_cycle = players->arr[iter]->live;
	while (++iter < players->size)
	{
		if (live_cycle <= players->arr[iter]->live)
		{
			winner_id = iter;
			live_cycle = players->arr[iter]->live;
		}
	}
	return(players->arr[winner_id]);
}

t_bool			end_dump(char *arena)
{
	write(1, "end bcs dump flag used\n", 23);
	print_arena(arena, MEM_SIZE/8);
	return (TRUE);
}

t_bool			end_game(t_vm *vm, t_players *players)
{
	t_player	*winner;
	
	write(1, "game has been end and the winner is bla-bla-bla\n", 49);
	winner = define_winner(players);
	return (TRUE);
}