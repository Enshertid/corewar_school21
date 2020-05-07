/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enshertid <enshertid@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 18:58:47 by enshertid         #+#    #+#             */
/*   Updated: 2020/05/05 11:43:13 by enshertid        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				main(int ac, char **av)
{
	t_data			data;

	init_data(&data, ac, av);
	write(1, "aaa", 3);
	cycle_of_game(&data.vm);
	destroy_data(&data);
	return (0);
}
