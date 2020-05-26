/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:20:12 by ediego            #+#    #+#             */
/*   Updated: 2020/05/26 12:20:14 by ediego           ###   ########.fr       */
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
	if (!(players->arr = ft_calloc(MAX_PLAYERS, sizeof(t_player*))))
		ft_error("error in malloc", "init_players", 3);
	players->dump_num = -1;
	players->size = MAX_PLAYERS;
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