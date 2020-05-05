//
// Created by Daniil&Ekaterina Naumenko on 05/05/2020.
//

#include "game.h"

t_bool			end_dump(char *arena)
{
	write(1, "end bcs dump flag used\n", 23);
	print_arena(arena, VM_SIZE);
	return (TRUE);
}

t_bool			end_game()
{
	write(1, "game has been end and the winner is bla-bla-bla\n", 49);
	return (TRUE);
}