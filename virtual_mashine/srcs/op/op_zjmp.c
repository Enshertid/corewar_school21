/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:19:02 by ediego            #+#    #+#             */
/*   Updated: 2020/05/26 12:19:04 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

void				op_zjmp(t_vm *vm, t_car *car, t_arg *arg)
{
	int				dir;

	(void)arg->first;
	if (car->carry)
	{
		dir = read_two_bytes(vm, (car->position + 1) % MEM_SIZE);
		car->position = get_pos(car, get_idx(dir));
	}
	else
		car->position = (car->position + 3) % MEM_SIZE;
}
