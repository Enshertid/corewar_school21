/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:21:16 by ediego            #+#    #+#             */
/*   Updated: 2020/05/26 12:21:17 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				main(int ac, char **av)
{
	t_vm		vm;

	init_data(&vm, ac, av);
	introduce(&vm.players);
	cycle_of_game(&vm);
	destroy_data(&vm);
	return (0);
}
