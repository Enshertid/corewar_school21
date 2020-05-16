/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 18:45:07 by ediego            #+#    #+#             */
/*   Updated: 2020/05/16 21:30:13 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "vm.h"

//void 		op_lld(t_vm *vm, t_car *car)
//{
//	int32_t value;
//	int8_t reg;
//	int ind;
//	int8_t args;
//
//	printf("LLD(%d): Cycle = %ld  POS = %d ", car->id, vm->current_cycle, car->position);
//	args = vm->arena[(car->position + 1) % MEM_SIZE];
//	if (check_arg(args) == DIR_CODE && check_arg(args << 2) == REG_CODE)
//	{
//		value = read_four_bytes(vm, car->position + 2);
//		reg = vm->arena[(car->position + 6) % MEM_SIZE];
//		if (reg > 0 && reg <= REG_NUMBER)
//			set_reg(car, reg, value, 1);
//	}
//	else if (check_arg(args) == IND_CODE && check_arg(args << 2) == REG_CODE)
//	{
//		ind = car->position + (read_two_bytes(vm, car->position + 2));
//		value = read_four_bytes(vm, ind);
//		reg = vm->arena[(car->position + 4) % MEM_SIZE];
//		if (reg > 0 && reg <= REG_NUMBER)
//			set_reg(car, reg, value, 1);
//	}
//	car->position += get_arg_step(args, 2, DIR_SIZE);
//	// car->code = vm->arena[car->position] - 1;
//	// if (car->code >= 0 && car->code < 16)
//	// 	car->cycle_to_action = vm->operations.op_cycles[car->code];
//}

static t_bool get_second(t_vm *vm, t_car *car, int8_t arg, int8_t *val)
{
	if (arg != REG)
		return (FALSE);
	*val = read_byte(vm, get_new_pos(car->position, car->step)) - 1;
	if (*val < 0 || *val > REG_NUMBER)
		return (FALSE);
}


static t_bool get_first(t_vm *vm, t_car *car, int8_t *arg, int32_t *val)
{
	if (*arg != DIR && *arg != IND)
		return(FALSE);
	if (*arg == DIR)
	{
		*val = read_two_bytes(vm, get_new_pos(car->position, car->step));
		*arg = DIR / 2;
	}
	else
		*val = read_four_bytes(vm,read_two_bytes(vm,
												 get_new_pos(car->position, car->step)));
	car->step += *arg;
	return (TRUE);
}

void		op_lld(t_vm *vm, t_car *car)
{
	int8_t	first;
	int8_t	sec;
	int32_t	first_val;
	int8_t	sec_val;
	
	first = determine_arg(vm->arena[get_new_pos(car->position, car->step)], 0);
	sec = determine_arg(vm->arena[get_new_pos(car->position, car->step)], 1);
	car->step += ARG_CHECK;
	if (first && sec)
		if (get_first(vm, car, &first, &first_val))
			if (get_second(vm, car, sec, &sec_val))
			{
				car->registers[sec_val] = first_val;
				car->carry = first_val == 0 ? TRUE : FALSE;
			}
	change_position(vm, car, OP_BYTE + ARG_CHECK + first + sec);
}
