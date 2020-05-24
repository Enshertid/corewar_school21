/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enshertid <enshertid@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 12:35:44 by enshertid         #+#    #+#             */
/*   Updated: 2020/05/24 12:35:44 by enshertid        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# define MINUS 0
# define PLUS 1

# define REG 1
# define DIR DIR_SIZE
# define IND IND_SIZE

# define ARG_CHECK 1
# define OP_BYTE 1

# define ONE 1
# define TWO 2
# define THREE 3

# define OP_NUM 16

#include "libft.h"
#include "carriages.h"
#include <stdio.h>

typedef struct		s_vm t_vm;

typedef struct		s_arg
{
	int8_t			first;
	int8_t			sec_d;
	int8_t			third;
	int32_t			first_val;
	int32_t			sec_d_val;
	int32_t			third_val;
}					t_arg;

typedef struct		s_operations
{
	void			(*func[16])(t_vm *vm, t_car *caret, t_arg *arg);
	int				op_cycles[16];
	t_arg			arg;
}					t_op;

void				op_live(t_vm *vm, t_car *car, t_arg *arg);
void				op_ld(t_vm *vm, t_car *car, t_arg *arg);
void				op_st(t_vm *vm, t_car *car, t_arg *arg);
void				op_add(t_vm *vm, t_car *car, t_arg *arg);
void				op_sub(t_vm *vm, t_car *car, t_arg *arg);
void				op_and(t_vm *vm, t_car *car, t_arg *arg);
void				op_or(t_vm *vm, t_car *car, t_arg *arg);
void				op_xor(t_vm *vm, t_car *car, t_arg *arg);
void				op_zjmp(t_vm *vm, t_car *car, t_arg *arg);
void				op_ldi(t_vm *vm, t_car *car, t_arg *arg);
void				op_sti(t_vm *vm, t_car *car, t_arg *arg);
void				op_fork(t_vm *vm, t_car *car, t_arg *arg);
void				op_lld(t_vm *vm, t_car *car, t_arg *arg);
void				op_lldi(t_vm *vm, t_car *car, t_arg *arg);
void				op_lfork(t_vm *vm, t_car *car, t_arg *arg);
void				op_aff(t_vm *vm, t_car *car, t_arg *arg);


int					determine_arg(unsigned char byte, unsigned int index);
void				set_array_of_operations(t_vm *vm);
void				set_array_of_cycles_to_op(t_vm *vm);

unsigned char		read_byte(t_vm *vm, int position);
int16_t				read_two_bytes(t_vm *vm, int position);
int32_t				read_four_bytes(t_vm *vm, int position);
int32_t				get_new_pos(int32_t position, int32_t step);

bool				get_arg_dir_four(t_vm *vm, t_car *car, int8_t sw_arg, int32_t *arg);
bool				get_arg_dir_two(t_vm *vm, t_car *car, int8_t *sw_arg,
		int32_t *arg);
void				change_position(t_car *car, t_arg *args, int8_t type);
void				write_to_reg_a_s(t_vm *vm, t_car *car, t_arg *arg, int8_t type);
bool				check_reg(t_vm *vm, t_car *car, int8_t byte, int32_t *arg);
void				write_to_reg(t_vm *vm, t_car *car, int32_t result, int8_t
third);
void				write_reg_to_arena(t_vm *vm, int value, int position);

int 				check_arg(uint8_t arg);
int 				get_arg_n(t_vm *vm, t_car *car, int8_t args);
void		 		set_reg(t_car *car, int8_t reg, int32_t value, bool edit_carry);
int 				get_arg_step(int args, int num, int dir_size);
bool 				valid_args(t_vm *vm, t_car *car, int8_t args);
// bool 				valid_args2(t_vm *vm, t_car *car, int8_t args);
bool		 		invalid_reg(t_vm *vm, t_car *car, int8_t args, int num);
int 				get_idx(int position);
bool			 	valid_args2(t_vm *vm, t_car *car, int8_t args);
int			 		get_pos(t_car *car, int pos);

#endif
