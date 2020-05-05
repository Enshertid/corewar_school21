//
// Created by Daniil&Ekaterina Naumenko on 01/05/2020.
//

#ifndef COREWAR_CARETS_H
# define COREWAR_CARETS_H

#include "libft.h"
#include "op.h"

# define ZERO_POS MEM_SIZE

#if (REG_SIZE == 4)
	typedef int32_t reg_type;
#elif (REG_SIZE == 2)
	typedef int16_t reg_type;
#elif (REG_SIZE == 8)
	typedef int64_t reg_type;
#endif

typedef struct 			s_car
{
	int32_t				id;
	int8_t				code;
	uint8_t				step;
	t_bool				carry;
	int32_t				position;
	int32_t				last_live_cycle;
	int32_t				cycle_to_action;
	reg_type			registers[REG_NUMBER];
	struct s_car		*next;
	struct s_car		*prev;
}						t_car;

t_car			*delete_from_begin(t_car *cur_car);
t_car			*delete_from_end(t_car *cur_car);
t_car			*delete_from_body(t_car *cur_car);
t_car			*try_to_kill_the_carret(t_car *head, t_car *cur_car,
													int cycle_to_die);
t_car			*new_carriage(t_car *head);
#endif
