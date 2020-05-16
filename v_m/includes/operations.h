/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 13:10:42 by ediego            #+#    #+#             */
/*   Updated: 2020/05/16 13:29:24 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# define REG 1
# define DIR 4
# define IND 2
# define ARG_CHECK 1
# define OP_BYTE 1
# define OP_NUM 16

#include "libft.h"
#include "carriages.h"
#include <stdio.h>

typedef struct		s_vm t_vm;

typedef struct		s_operations
{
	void			(*func[16])(t_vm *vm, t_car *caret);
	int				op_cycles[16];
}					t_op;

void				op_live(t_vm *vm, t_car *car);
void				op_ld(t_vm *vm, t_car *car);
void				op_st(t_vm *vm, t_car *car);
void				op_add(t_vm *vm, t_car *car);
void				op_sub(t_vm *vm, t_car *car);
void				op_and(t_vm *vm, t_car *car);
void				op_or(t_vm *vm, t_car *car);
void				op_xor(t_vm *vm, t_car *car);
void				op_zjmp(t_vm *vm, t_car *car);
void				op_ldi(t_vm *vm, t_car *car);
void				op_sti(t_vm *vm, t_car *car);
void				op_fork(t_vm *vm, t_car *car);
void				op_lld(t_vm *vm, t_car *car);
void				op_lldi(t_vm *vm, t_car *car);
void				op_lfork(t_vm *vm, t_car *car);
void				op_aff(t_vm *vm, t_car *car);

int					determine_arg(unsigned char byte, unsigned int index);
void				set_array_of_operations(t_vm *vm);
void				set_array_of_cycles_to_op(t_vm *vm);

unsigned char		read_byte(t_vm *vm, int position);
int16_t				read_two_bytes(t_vm *vm, int position);
int32_t				read_four_bytes(t_vm *vm, int position);
int32_t				get_new_pos(int32_t position, int32_t step);

t_bool				get_arg_dir_four(t_vm *vm, t_car *car, int8_t sw_arg, int32_t *arg);
t_bool				get_arg_dir_two(t_vm *vm, t_car *car, int8_t sw_arg, int32_t *arg);
void				use_args(t_vm *vm, t_car *car, int32_t result, int8_t third);
void				write_reg_to_arena(t_vm *vm, int value, int position);

int 				check_arg(uint8_t arg);
int 				get_arg_n(t_vm *vm, t_car *car, int8_t args);
void 				set_reg(t_car *car, int8_t reg, int value, t_bool carry);
int 				get_arg_step(int args, int num, int dir_size);
t_bool 				valid_args(t_vm *vm, t_car *car, int8_t args);
t_bool		 		invalid_reg(t_vm *vm, t_car *car, int8_t args, int num);
int 				get_idx(int position);
t_bool			 	valid_args2(t_vm *vm, t_car *car, int8_t args);
int			 		calc_pos(t_car *car, int pos);

#endif
