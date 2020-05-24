/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 18:39:34 by ediego            #+#    #+#             */
/*   Updated: 2020/05/24 16:43:36 by enshertid        ###   ########.fr       */
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
