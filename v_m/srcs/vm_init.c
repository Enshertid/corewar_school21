/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 14:19:35 by ediego            #+#    #+#             */
/*   Updated: 2020/05/24 14:19:37 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		copy_excode(t_vm *vm, t_players *players)
{
	int i;
	int pos;
	
	i = 0;
	while (i < (int)players->iter)
	{
		pos = ((MEM_SIZE)/(int)players->iter) * i;
		ft_memcpy(&(vm->arena[pos]), players->arr[i]->ex_code, players->arr[i]->ex_size);
		i++;
	}
}