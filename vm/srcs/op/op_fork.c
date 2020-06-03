/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 21:48:52 by ediego            #+#    #+#             */
/*   Updated: 2020/05/24 22:01:47 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

void				op_fork(t_vm *vm, t_car *car, t_arg *arg)
{
	t_car			*new;
	int32_t			pos;
	int32_t			dir;

	(void)arg->first;
	dir = read_two_bytes(vm, (car->position + 1) % MEM_SIZE) % IDX_MOD;
	pos = get_pos(car, dir);
	new = copy_caret(car, pos, ++vm->id_cars);
	add_caret(&vm->carriages, new);
	car->position = (car->position + 3) % MEM_SIZE;
	vm->num_of_car++;
}
