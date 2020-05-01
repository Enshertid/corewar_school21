/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 16:31:22 by ediego            #+#    #+#             */
/*   Updated: 2020/04/30 14:46:44 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# define VM_SIZE (MEM_SIZE / 4)

#include "carets.h"

static int GET_C[17] = {0, 10, 5, 5, 10, 10, 6, 6, 6, 20, 25, 25, 800, 10, 50, 1000, 2};

typedef struct			s_vm
{
	char			arena[MEM_SIZE];
	int				last_live_id;
	int				current_cycle;
	int				count_live;
	int				cycle_to_die;
	int				count_checks;
	int				iter;
	size_t			dump_count;
	size_t			dump_value;
	t_car			*carriages;
}						t_vm;

#endif
