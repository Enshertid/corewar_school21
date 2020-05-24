/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 14:11:45 by ediego            #+#    #+#             */
/*   Updated: 2020/05/24 14:11:49 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				main(int ac, char **av)
{
	t_vm vm;
	
	init_data(&vm, ac, av);
	introduce(&vm.players);
	cycle_of_game(&vm);
	destroy_data(&vm);
	return (0);
}
