/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 18:44:23 by enshertid         #+#    #+#             */
/*   Updated: 2020/05/24 17:06:20 by enshertid        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "players.h"
# include "vm.h"

void		init_data(t_vm *vm, int ac, char **av);
void		cycle_of_game(t_vm *vm);
void		destroy_data(t_vm *vm);
void		introduce(t_players *players);

#endif
