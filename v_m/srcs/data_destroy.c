/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 14:09:11 by ediego            #+#    #+#             */
/*   Updated: 2020/05/24 14:09:16 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "vis.h"

void			destroy_data(t_vm *vm)
{
	int i;

	i = 0;
	while (i < vm->players.iter)
	{
		free(vm->players.arr[i]->name);
		free(vm->players.arr[i]->comment);
		free(vm->players.arr[i]->ex_code);
		free(vm->players.arr[i]);
		i++;
	}
	free(vm->players.arr);
}
