/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>        +#+  +:+       +#+              */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 12:33:30 by enshertid         #+#    #+#             */
/*   Updated: 2020/05/24 12:33:30 by enshertid        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "corewar.h"

void		print_arena(const void *arena, size_t size)
{
	size_t			i;
	size_t 			j;
	unsigned char	*p;
	char 			*str;
	
	str = "0123456789abcdef";
	p = (unsigned char *)arena;
	i = 0;
	while (i < size)
	{
		j = 0;
		write(1, "0x", 2);
		write(1, &str[((i >> 8) / 16) % 16], 1);
		write(1, &str[(i >> 8) % 16], 1);
		write(1, &str[(i / 16) % 16], 1);
		write(1, &str[i % 16], 1);
		write(1, " : ", 3);
		while (j < 64 && i + j < size)
		{
			write(1, &str[(*(p + i + j)/16) % 16], 1);
			write(1, &str[*(p + i + j) % 16], 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i += 64;
	}
}
