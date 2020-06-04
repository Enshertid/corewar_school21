/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriages.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:25:06 by ediego            #+#    #+#             */
/*   Updated: 2020/05/26 12:25:07 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CARRIAGES_H
# define CARRIAGES_H

# include "libft.h"
# include "op.h"

# define OP_BYTE 1

typedef int32_t			t_reg_type;

typedef struct s_vm		t_vm;

typedef struct			s_car
{
	int32_t				id;
	int8_t				code;
	uint8_t				step;
	bool				carry;
	int32_t				position;
	int32_t				last_live_cycle;
	int32_t				cycle_to_action;
	t_reg_type			registers[REG_NUMBER];
	struct s_car		*next;
	struct s_car		*prev;
}						t_car;

t_car					*delete_from_begin(t_car **head, t_car *cur_car);
t_car					*delete_from_end(t_car *cur_car);
t_car					*delete_from_body(t_car *cur_car);
t_car					*try_to_kill_the_carret(t_vm *vm, t_car **head,
											t_car *cur_car, int cycle_to_die);
t_car					*create_caret(int position_on_arena, int id);
t_car					*copy_caret(t_car *parent, int32_t position,
																int32_t id);

void					add_caret(t_car **head, t_car *new_node);

#endif
