/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:25:28 by ediego            #+#    #+#             */
/*   Updated: 2020/05/26 12:25:30 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "carriages.h"
# include "vm.h"
# include "op.h"

t_car				*check_caret(t_vm *vm, t_car *caret);
bool				check_live(t_vm *vm);

bool				end_dump(t_vm *vm);
bool				end_game(t_vm *vm, t_players *players);

#endif
