/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enshertid <enshertid@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 13:10:42 by ediego            #+#    #+#             */
/*   Updated: 2020/05/05 11:39:11 by enshertid        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H


# define REG 1
# define DIR 4
# define IND 2


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

unsigned char		read_reg_arg(t_vm *vm, int position);
int16_t				read_ind_arg(t_vm *vm, int position);
int32_t				read_dir_arg(t_vm *vm, int position);

void				write_reg_to_arena(t_vm *vm, int value, int position);
int32_t				get_new_pos(int32_t position, int32_t step);

#endif
