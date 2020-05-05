//
// Created by Daniil&Ekaterina Naumenko on 05/05/2020.
//

#ifndef GAME_H
#define GAME_H

#include "corewar.h"

t_car			*check_caret(t_vm *vm, t_car *caret, t_op op);
t_bool			check_live(t_vm *vm);

t_bool			end_dump(char *arena);
t_bool			end_game();


#endif
