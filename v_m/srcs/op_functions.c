/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:21:31 by ediego            #+#    #+#             */
/*   Updated: 2020/05/26 12:21:32 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

void	set_array_of_operations(t_vm *vm)
{
	vm->operations.func[0] = &op_live;
	vm->operations.func[1] = &op_ld;
	vm->operations.func[2] = &op_st;
	vm->operations.func[3] = &op_add;
	vm->operations.func[4] = &op_sub;
	vm->operations.func[5] = &op_and;
	vm->operations.func[6] = &op_or;
	vm->operations.func[7] = &op_xor;
	vm->operations.func[8] = &op_zjmp;
	vm->operations.func[9] = &op_ldi;
	vm->operations.func[10] = &op_sti;
	vm->operations.func[11] = &op_fork;
	vm->operations.func[12] = &op_lld;
	vm->operations.func[13] = &op_lldi;
	vm->operations.func[14] = &op_lfork;
	vm->operations.func[15] = &op_aff;
}

void	set_array_of_cycles_to_op(t_vm *vm)
{
	vm->operations.op_cycles[0] = 10;
	vm->operations.op_cycles[1] = 5;
	vm->operations.op_cycles[2] = 5;
	vm->operations.op_cycles[3] = 10;
	vm->operations.op_cycles[4] = 10;
	vm->operations.op_cycles[5] = 6;
	vm->operations.op_cycles[6] = 6;
	vm->operations.op_cycles[7] = 6;
	vm->operations.op_cycles[8] = 20;
	vm->operations.op_cycles[9] = 25;
	vm->operations.op_cycles[10] = 25;
	vm->operations.op_cycles[11] = 800;
	vm->operations.op_cycles[12] = 10;
	vm->operations.op_cycles[13] = 50;
	vm->operations.op_cycles[14] = 1000;
	vm->operations.op_cycles[15] = 2;
}
