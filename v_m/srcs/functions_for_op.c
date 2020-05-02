/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_for_op.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 12:47:35 by ediego            #+#    #+#             */
/*   Updated: 2020/05/02 18:47:30 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void functions_for_op(t_data *data, t_car *car)
{
	void (*func[16])(t_vm *vm, t_car *);

	func[0] = &op_live;
	func[1] = &op_ld;
	func[2] = &op_st;
	func[3] = &op_add;
	func[4] = &op_sub;
	func[5] = &op_and;
	func[6] = &op_or;
	func[7] = &op_xor;
	func[8] = &op_zjmp;
	func[9] = &op_ldi;
	func[10] = &op_sti;
	func[11] = &op_fork;
	func[12] = &op_lld;
	func[13] = &op_lldi;
	func[14] = &op_lfork;
	func[15] = &op_aff;


	if (car->code > 0 && car->code < 17)
		func[car->code - 1](&data->vm, car);
}

