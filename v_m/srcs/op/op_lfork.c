/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 18:46:32 by ediego            #+#    #+#             */
/*   Updated: 2020/05/09 00:22:46 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void 		op_lfork(t_vm *vm, t_car *car)
{
	t_car	*new;
	int32_t pos;

	pos = get_2byte(vm, car->position + 2);
	new = copy_caret(car, (car->position + pos) % MEM_SIZE, ++vm->id_cars);
	add_caret(&vm->carriages, new);
	car->position = (car->position + 3) % MEM_SIZE;
}
