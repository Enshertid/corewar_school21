/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dup_inst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 15:21:15 by jgroleo           #+#    #+#             */
/*   Updated: 2020/05/24 12:58:18 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void		ft_check_dup_lab(t_vector_token *t, t_validation *val)
{
	int				row;
	int				row_d;

	row = 0;
	while (row < vec_size(&t))
	{
		if (t[row][0].type == 0)
		{
			row_d = 0;
			while (row_d < vec_size(&t))
			{
				if (t[row_d][0].type == 0 && row != row_d &&
				ft_strcmp(t[row][0].value, t[row_d][0].value) == 0)
				{
					warning_add(ERROR, 3, "dublicate instruction in line №",
								ft_itoa_static(row_d + val->extr + 1, 10), ".");
					val->error = 1;
				}
				row_d++;
			}
		}
		row++;
	}
}
