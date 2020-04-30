/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 18:58:47 by enshertid         #+#    #+#             */
/*   Updated: 2020/04/16 16:33:24 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "stdio.h"

void			init_data(t_data *data, int ac, char **av)
{
	ft_memset(data, 0, sizeof(t_data));
	init_players(&data->players);
	data->pars.ac = ac;
	data->pars.av = av;
	data->pars.i = 1;
}

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

int				main(int ac, char **av)
{
	t_data			data;

	init_data(&data, ac, av);
	parsing(&data.pars, &data.players);
	init_vm(&data.vm, &data);
	destroy_data(&data);
	return (0);
}
