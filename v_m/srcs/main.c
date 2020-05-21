/* *********************************************`***************************** */
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
	t_vm vm;
	
	init_data(&vm, ac, av);
	introduce(&vm.players);
	vm.debug = false;
	cycle_of_game(&vm);
	destroy_data(&vm);
	return (0);
}
