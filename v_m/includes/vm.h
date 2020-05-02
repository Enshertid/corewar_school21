/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 16:31:22 by ediego            #+#    #+#             */
/*   Updated: 2020/05/02 16:55:28 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# define VM_SIZE (MEM_SIZE / 4)

#include "corewar.h"
#include "carriages.h"

typedef struct		s_vm
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
}					t_vm;

#endif
