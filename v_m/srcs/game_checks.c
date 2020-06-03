/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:20:28 by ediego            #+#    #+#             */
/*   Updated: 2020/05/26 12:20:30 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "carriages.h"
#include "stdio.h"

bool			check_live(t_vm *vm)
{
	t_car		*tmp;

	vm->count_checks++;
	tmp = vm->carriages;
	while (tmp)
		tmp = try_to_kill_the_carret(vm, &vm->carriages, tmp, vm->cycle_to_die);
	if (vm->count_live >= NBR_LIVE || vm->count_checks >= MAX_CHECKS)
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		vm->count_checks = 0;
	}
	vm->iter = 0;
	vm->count_live = 0;
	return (vm->carriages ? true : false);
}

t_car			*check_caret(t_vm *vm, t_car *caret)
{
	caret->last_live_cycle++;
	if (!caret->cycle_to_action)
	{
		caret->code = read_byte(vm, caret->position) - 1;
		if (caret->code >= 0 && caret->code < REG_NUMBER)
			caret->cycle_to_action = vm->operations.op_cycles[caret->code] - 1;
		else
			caret->position = get_pos(caret, OP_BYTE);
	}
	else if (!(--caret->cycle_to_action))
		vm->operations.func[caret->code](vm, caret, &vm->operations.arg);
	return (caret->next);
}
