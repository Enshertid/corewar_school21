/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 15:21:15 by jgroleo           #+#    #+#             */
/*   Updated: 2020/05/29 16:04:31 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int		ft_any_error(t_validation *val)
{
	if (val->not_file == 1 || val->no_newline_empty == 1)
		return (0);
	if ((val->have_instructions == 0 || val->name == 0 ||
	val->comment == 0 || val->error == 1))
		return (1);
	else
		return (0);
}

int		ft_validation(const char *const *argv)
{
	t_validation	*val;

	warning_create();
	val = ft_create_val();
	assembler(argv + 1, val);
	if (ft_any_error(val) == 1)
	{
		if (val->name == 0 && val->no_n_start == 0 && val->not_file == 0)
			warning_add(ERROR, 1, "no name found.");
		if (val->comment == 0 && val->no_c_start == 0 && val->not_file == 0)
			warning_add(ERROR, 1, "no comment found.");
		if (val->have_instructions == 0 && val->not_file == 0)
			warning_add(ERROR, 1, "no instruction found.");
		free(val);
		warning_print();
		warning_destroy();
		return (0);
	}
	free(val);
	warning_print();
	warning_destroy();
	return (1);
}
