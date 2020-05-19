/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 16:31:22 by ediego            #+#    #+#             */
/*   Updated: 2020/05/18 16:45:02 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

#include "libft.h"
#include "carriages.h"
#include "players.h"
#include "operations.h"
#include "op.h"

typedef struct		s_vm
{
	t_players 		players;
	char			arena[MEM_SIZE];
	int				count_live;
	int				count_checks;
	int				cycle_to_die;
	int				iter;
	int				num_of_car;
	size_t			dump_value;
	size_t			current_cycle;
	t_bool			dump_flag;
	size_t 			id_cars;
	t_car			*carriages;
	t_op			operations;
	t_bool 			debug;
}					t_vm;

void		print_arena(const void *arena, size_t size);
void		copy_excode(t_vm *vm, t_players *players);

#endif
