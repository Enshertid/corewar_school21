//
// Created by Daniil&Ekaterina Naumenko on 01/05/2020.
//

#ifndef COREWAR_CARETS_H
# define COREWAR_CARETS_H

#include "libft.h"
#include "op.h"
# define OP_NUM 16

//typedef void (*operations(struct s_car *car));

typedef struct 			s_car
{
	int32_t				id;
	int8_t				code;
	uint8_t				step;
	t_bool				carry;
	int32_t 			position;
	int32_t				last_live_cycle;
	int32_t				cycle_to_action;
	int32_t				registers[REG_NUMBER];
	struct s_car		*next;
	struct s_car		*prev;
}						t_car;

t_car			*delete_from_begin(t_car *cur_car);
t_car			*delete_from_end(t_car *cur_car);
t_car			*delete_from_body(t_car *cur_car);

#endif
