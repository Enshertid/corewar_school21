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
#include "op.h"
#include "parsing.h"
#include "players.h"
#include "vm.h"
#include "carriages.h"
#include "operations.h"

typedef struct			s_data
{
	t_pars				pars;
	t_players			players;
	t_vm 				vm;
}						t_data;

void		parsing(t_pars *pars, t_players *players);
void		init_vm(t_vm *vm, t_data *data);
void		print_arena(const void *arena, size_t size);
void		cycle_of_game(t_data *data);
void		functions_for_op(t_data *data, t_car *car);

#endif
