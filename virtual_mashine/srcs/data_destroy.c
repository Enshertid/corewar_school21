/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 20:53:19 by user              #+#    #+#             */
/*   Updated: 2020/06/03 20:53:20 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
