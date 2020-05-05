/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_for_op.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enshertid <enshertid@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 12:47:35 by ediego            #+#    #+#             */
/*   Updated: 2020/05/05 11:42:35 by enshertid        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	set_array_of_operations(t_data *data)
{
	data->vm.operations.func[0] = NULL;
	data->vm.operations.func[1] = &op_live;
	data->vm.operations.func[2] = &op_ld;
	data->vm.operations.func[3] = &op_st;
	data->vm.operations.func[4] = &op_add;
	data->vm.operations.func[5] = &op_sub;
	data->vm.operations.func[6] = &op_and;
	data->vm.operations.func[7] = &op_or;
	data->vm.operations.func[8] = &op_xor;
	data->vm.operations.func[9] = &op_zjmp;
	data->vm.operations.func[10] = &op_ldi;
	data->vm.operations.func[11] = &op_sti;
	data->vm.operations.func[12] = &op_fork;
	data->vm.operations.func[13] = &op_lld;
	data->vm.operations.func[14] = &op_lldi;
	data->vm.operations.func[15] = &op_lfork;
	data->vm.operations.func[16] = &op_aff;
}

void	set_array_of_cycles_to_op(t_data *data)
{
	data->vm.operations.op_cycles[0] = 0;
	data->vm.operations.op_cycles[1] = 10;
	data->vm.operations.op_cycles[2] = 5;
	data->vm.operations.op_cycles[3] = 5;
	data->vm.operations.op_cycles[4] = 10;
	data->vm.operations.op_cycles[5] = 10;
	data->vm.operations.op_cycles[6] = 6;
	data->vm.operations.op_cycles[7] = 6;
	data->vm.operations.op_cycles[8] = 6;
	data->vm.operations.op_cycles[9] = 20;
	data->vm.operations.op_cycles[10] = 25;
	data->vm.operations.op_cycles[11] = 25;
	data->vm.operations.op_cycles[12] = 800;
	data->vm.operations.op_cycles[13] = 10;
	data->vm.operations.op_cycles[14] = 50;
	data->vm.operations.op_cycles[15] = 1000;
	data->vm.operations.op_cycles[16] = 2;
}
