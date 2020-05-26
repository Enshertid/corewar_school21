/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carets_op_delete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:19:28 by ediego            #+#    #+#             */
/*   Updated: 2020/05/26 12:19:29 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>
#include "carriages.h"

t_car			*delete_from_end(t_car *cur_car)
{
	cur_car->prev->next = NULL;
	free(cur_car);
	return (NULL);
}

t_car			*delete_from_begin(t_car **head, t_car *cur_car)
{
	if (cur_car->next)
	{
		cur_car = cur_car->next;
		free(cur_car->prev);
		cur_car->prev = NULL;
		*head = cur_car;
	}
	else
	{
		free(cur_car);
		cur_car = NULL;
		*head = NULL;
	}
	return (cur_car);
}

t_car			*delete_from_body(t_car *cur_car)
{
	t_car			*tmp;

	tmp = cur_car;
	cur_car = cur_car->next;
	cur_car->prev = tmp->prev;
	cur_car->prev->next = cur_car;
	free(tmp);
	return (cur_car);
}

t_car			*try_to_kill_the_carret(t_vm *vm, t_car **head, t_car *cur_car,
															int cycle_to_die)
{
	if (cur_car->last_live_cycle >= cycle_to_die)
	{
		--vm->num_of_car;
		if (cur_car->prev && !cur_car->next)
			return (delete_from_end(cur_car));
		else if (cur_car == *head)
			return (delete_from_begin(head, cur_car));
		else if (cur_car->prev && cur_car->next)
			return (delete_from_body(cur_car));
	}
	return (cur_car->next);
}
