/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:19:57 by ediego            #+#    #+#             */
/*   Updated: 2020/06/03 11:57:40 by ediego           ###   ########.fr       */
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
