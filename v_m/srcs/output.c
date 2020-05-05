//
// Created by Daniil&Ekaterina Naumenko on 05/05/2020
//
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
		while (j < 64 && i + j < size)
		{
			write(1, &str[(*(p + i + j)/16) % 16], 1);
			write(1, &str[*(p + i + j) % 16], 1);
			// if (j % 2) // comment me!
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i += 64;
	}
}