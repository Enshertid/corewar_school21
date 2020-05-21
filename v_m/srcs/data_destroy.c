//
// Created by Daniil&Ekaterina Naumenko on 05/05/2020.
//

#include "corewar.h"

void			destroy_data(t_vm *vm)
{
	int i = 0;
	
	while(i < vm->players.iter)
	{
		free(vm->players.arr[i]->name);
		free(vm->players.arr[i]->comment);
		free(vm->players.arr[i]->ex_code);
		free(vm->players.arr[i]);
		i++;
	}
	free(vm->players.arr);
}