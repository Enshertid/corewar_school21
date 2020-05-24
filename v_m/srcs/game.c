/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 14:11:00 by ediego            #+#    #+#             */
/*   Updated: 2020/05/24 14:11:02 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "vis.h"

void			cycle_of_game(t_vm *vm)
{
	bool		flag_of_end;
	t_car		*tmp;

	flag_of_end = false;
	while (!flag_of_end)
	{
		if (vm->current_cycle++ == vm->dump_value && end_dump(vm))
			break ;
		tmp = vm->carriages;
		while (tmp)
			tmp = check_caret(vm, tmp);
		if (++vm->iter >= vm->cycle_to_die && !check_live(vm))
			flag_of_end = end_game(vm, &vm->players);
	}
}
