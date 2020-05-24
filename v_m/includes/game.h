/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enshertid <enshertid@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 12:35:52 by enshertid         #+#    #+#             */
/*   Updated: 2020/05/24 12:35:52 by enshertid        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GAME_H
#define GAME_H

#include "carriages.h"
#include "vm.h"
#include "op.h"

t_car			*check_caret(t_vm *vm, t_car *caret);
bool			check_live(t_vm *vm);

bool			end_dump(t_vm *vm);
bool			end_game(t_vm *vm, t_players *players);


#endif
