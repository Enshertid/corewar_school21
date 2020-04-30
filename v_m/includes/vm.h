/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 16:31:22 by ediego            #+#    #+#             */
/*   Updated: 2020/04/30 14:46:44 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
#define VM_SIZE (MEM_SIZE / 4)
// #include "op.h"

static int GET_C[17] = {0, 10, 5, 5, 10, 10, 6, 6, 6, 20, 25, 25, 800, 10, 50, 1000, 2};

typedef struct 			s_car
{
	int32_t				id;
	int32_t 			id_player;
	int32_t 			position;
	t_bool 				carry;
	int8_t				code;
	int32_t 			last_live_cycle;
	int32_t 			cycle_to_action;
	uint8_t 			step;
	int32_t 			registers[REG_NUMBER];
	struct s_car		*next;
}						t_car;


typedef struct  		s_vm
{
	char			arena[MEM_SIZE];
	int				last_live_id;
	int				current_cycle;
	int 			count_live;
	int				cycle_to_die;
	int 			count_checks;
	t_car 			*carriages;
	

}						t_vm;

#endif
