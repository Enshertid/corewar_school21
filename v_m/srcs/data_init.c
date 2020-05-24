/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enshertid <enshertid@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 12:32:27 by enshertid         #+#    #+#             */
/*   Updated: 2020/05/24 12:59:52 by enshertid        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"
#include "vm.h"
#include "carriages.h"
#include "op.h"
#include "libft.h"
#include "players.h"
#include "operations.h"
#include "vis.h"

static void		init_players(t_players *players)
{
	players->arr = ft_calloc(MAX_PLAYERS, sizeof(t_player*));
	players->dump_num = -1;
	players->size = MAX_PLAYERS;
	players->debug_mode = false;
}

void			init_data(t_vm *vm, int ac, char **av)
{
	ft_memset(vm, 0, sizeof(t_vm));
	set_array_of_operations(vm);
	set_array_of_cycles_to_op(vm);
	init_players(&vm->players);
	parsing(&vm->players, ac, av);
	init_vm(vm, &vm->players);
}
