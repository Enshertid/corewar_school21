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
		if (live_cycle <= players->arr[iter]->live)
		{
			winner_id = iter;
			live_cycle = players->arr[iter]->live;
		}
	}
	return(players->arr[winner_id]);
}

void			print_car(t_vm *vm)
{
	t_car *car;

	car = vm->carriages;
	while(car)
	{
		printf(" OP:%d(%d) POS = %d \n", (car->code + 1), car->id, car->position);
		car = car->next;
	}
}

t_bool			end_dump(t_vm *vm, t_players *players)
{
	t_player	*winner;
	
	winner = define_winner(players);
	write(1, "end bcs dump flag used\n", 23);
	print_car(vm);
	print_arena(vm->arena, MEM_SIZE / 8);
	printf("%s (player %d) won!\n", winner->name,
		   winner->id);
	return (TRUE);
}

t_bool			end_game(t_vm *vm, t_players *players)
{
	t_player	*winner;
	
	write(1, "game has been end and the winner is bla-bla-bla\n", 49);
	winner = define_winner(players);
	print_arena(vm->arena, MEM_SIZE / 8);
	printf("%s (player %d) won!\n", winner->name,
		   winner->id);
	return (TRUE);
}
