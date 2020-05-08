//
// Created by Daniil&Ekaterina Naumenko on 05/05/2020.
//

#include "vm.h"

void		copy_excode(t_vm *vm, t_players *players)
{
	int i;
	int pos;
	
	i = 0;
	while (i < (int)players->iter)
	{
		pos = ((MEM_SIZE)/(int)players->iter) * i;
		ft_memcpy(&(vm->arena[pos]), players->arr[i]->ex_code, players->arr[i]->ex_size);
		i++;
	}
}