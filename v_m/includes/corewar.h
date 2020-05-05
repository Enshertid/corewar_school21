/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 18:44:23 by enshertid         #+#    #+#             */
/*   Updated: 2020/04/16 ,22:17:06 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

#include "libft.h"
#include "pars.h"
#include "players.h"
#include "vm.h"
#include "op.h"

typedef struct			s_data
{
	t_players			players;
	t_vm 				vm;
}						t_data;

void		parsing(t_players *players, int ac, char **av);

void		init_data(t_data *data, int ac, char **av);

void		set_array_of_operations(t_data *data);

void		print_arena(const void *arena, size_t size);

void		cycle_of_game(t_vm *vm);

void		destroy_data(t_data *data);

#endif
