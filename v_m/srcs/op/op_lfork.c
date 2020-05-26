/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:15:56 by ediego            #+#    #+#             */
/*   Updated: 2020/05/26 12:15:58 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

void			op_lfork(t_vm *vm, t_car *car, t_arg *arg)
{
	t_car		*new;
	int32_t		pos;
	int32_t		dir;

	(void)arg->first;
	dir = read_two_bytes(vm, (car->position + 1) % MEM_SIZE);
	pos = get_pos(car, dir);
	new = copy_caret(car, pos, ++vm->id_cars);
	add_caret(&vm->carriages, new);
	car->position = (car->position + 3) % MEM_SIZE;
	vm->num_of_car++;
}
