/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 13:10:42 by ediego            #+#    #+#             */
/*   Updated: 2020/05/02 18:49:07 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

#include "corewar.h"

void 		op_live(t_vm *vm, t_car *car);
void 		op_ld(t_vm *vm, t_car *car);
void 		op_st(t_vm *vm, t_car *car);
void 		op_add(t_vm *vm, t_car *car);
void 		op_sub(t_vm *vm, t_car *car);
void 		op_and(t_vm *vm, t_car *car);
void 		op_or(t_vm *vm, t_car *car);
void 		op_xor(t_vm *vm, t_car *car);
void 		op_zjmp(t_vm *vm, t_car *car);
void 		op_ldi(t_vm *vm, t_car *car);
void 		op_sti(t_vm *vm, t_car *car);
void 		op_fork(t_vm *vm, t_car *car);
void 		op_lld(t_vm *vm, t_car *car);
void 		op_lldi(t_vm *vm, t_car *car);
void 		op_lfork(t_vm *vm, t_car *car);
void 		op_aff(t_vm *vm, t_car *car);

#endif