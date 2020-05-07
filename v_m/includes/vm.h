/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 16:31:22 by ediego            #+#    #+#             */
/*   Updated: 2020/05/07 12:26:58 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# define VM_SIZE (MEM_SIZE / 4)

#include "op.h"
#include "corewar.h"
#include "carriages.h"
#include "operations.h"

typedef struct		s_vm
{
	char			arena[MEM_SIZE];
	int				last_live_id;
	int				current_cycle;
	int				count_live;
	int				count_checks;
	int				cycle_to_die;
	int				iter;
	size_t			dump_count;
	size_t			dump_value;
	t_car			*carriages;
	t_op			operations;
	t_players 		*players;
}					t_vm;

void		print_arena(const void *arena, size_t size);
void		copy_excode(t_vm *vm, t_players *players);

t_car		*new_carriage(t_car *head);

#endif
