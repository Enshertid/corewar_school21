/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 20:54:46 by user              #+#    #+#             */
/*   Updated: 2020/06/03 20:54:47 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			print_addr(int i)
{
	char			*str;

	str = "0123456789abcdef";
	write(1, "0x", 2);
	write(1, &str[((i >> 8) / 16) % 16], 1);
	write(1, &str[(i >> 8) % 16], 1);
	write(1, &str[(i / 16) % 16], 1);
	write(1, &str[i % 16], 1);
	write(1, " : ", 3);
}

void				print_arena(const void *arena, size_t size)
{
	size_t			i;
	size_t			j;
	unsigned char	*p;
	char			*str;

	str = "0123456789abcdef";
	p = (unsigned char *)arena;
	i = 0;
	while (i < MEM_SIZE)
	{
		print_addr(i);
		j = 0;
		while (j < size && i + j < MEM_SIZE)
		{
			write(1, &str[(*(p + i + j) / 16) % 16], 1);
			write(1, &str[*(p + i + j) % 16], 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i += size;
	}
}
