//
// Created by Daniil&Ekaterina Naumenko on 05/05/2020.
//

#include "corewar.h"

void			destroy_data(t_data *data)
{
	size_t i = 0;
	while(i < data->players.iter)
	{
		free(data->players.arr[i]->name);
		free(data->players.arr[i]->comment);
		// free(data->players.arr[i]->ex_code);
		free(data->players.arr[i]);
		i++;
	}
	free(data->players.arr);
}