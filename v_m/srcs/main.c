/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enshertid <enshertid@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 18:58:47 by enshertid         #+#    #+#             */
/*   Updated: 2020/04/03 19:51:58 by enshertid        ###   ########.fr       */
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
	parsing(&data->pars, &data->players);
}

int				main(int ac, char **av)
{
	t_data			data;

	init_data(&data, ac, av);
	return (0);
}
