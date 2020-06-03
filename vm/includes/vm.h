/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 20:56:07 by user              #+#    #+#             */
/*   Updated: 2020/06/03 20:56:36 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "libft.h"
# include "carriages.h"
# include "players.h"
# include "operations.h"
# include "op.h"

typedef struct			s_vm
{
	t_players			players;
	char				arena[MEM_SIZE];
	int8_t				winner_id;
	int8_t				dump_size;
	int32_t				count_live;
	int32_t				count_checks;
	int32_t				cycle_to_die;
	int32_t				iter;
	int32_t				num_of_car;
	int32_t				dump_value;
	int32_t				current_cycle;
	size_t				id_cars;
	t_car				*carriages;
	t_op				operations;
	bool				aff;
}						t_vm;

void					print_arena(const void *arena, size_t size);
void					init_vm(t_vm *vm, t_players *players);

#endif
