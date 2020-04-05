/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enshertid <enshertid@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 16:16:39 by user              #+#    #+#             */
/*   Updated: 2020/04/04 10:52:04 by enshertid        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include <stdio.h>
#include <stdlib.h>
#include "reader.h"

static t_bool	line_equal_to_prev(const char *line, size_t lenght)
{
	static char		prev_line[17];
	static size_t	prev_lenght = 0;
	size_t			pos;
	t_bool			equals;

	equals = TRUE;
	if (!prev_lenght || lenght != prev_lenght)
		equals = FALSE;
	pos = 0;
	while (pos < lenght)
	{
		if (line[pos] != prev_line[pos])
		{
			equals = FALSE;
			break ;
		}
		++pos;
	}
	ft_memcpy(prev_line, line, lenght + 1);
	prev_lenght = lenght;
	return (equals);
}

static void		print_line(const char *line, size_t lenght)
{
	static char			hex_line[40];
	const char			alphabet[] = "0123456789abcdef";
	size_t				pos;

	pos = 0;
	while (lenght)
	{
		lenght -= 2;
		hex_line[pos++] = alphabet[(unsigned char)(line[0]) / 16];
		hex_line[pos++] = alphabet[(unsigned char)(line[0]) & 15];
		hex_line[pos++] = alphabet[(unsigned char)(line[1]) / 16];
		hex_line[pos++] = alphabet[(unsigned char)(line[1]) & 15];
		if (lenght)
			hex_line[pos++] = ' ';
		line += 2;
	}
	buf_add_strn(hex_line, pos);
	buf_add_chr('\n', 1);
	buf_flush();
}

static void		print_total_symbols(size_t symbols)
{
	static int	field_width = 7;
	char		a[10];

	if (symbols > 0xfffffe && ((symbols + 1) & symbols) == 0)
		field_width += 1;
	sprintf(a, "%0*lx ", field_width, symbols);
	buf_add_str(a);
}

void		print_hex(const int fd)
{
	char	cur_line[17];
	size_t	ret;
	size_t	printed_symbols;
	t_bool	prev_line_is_equal;

	printed_symbols = 0;
	prev_line_is_equal = FALSE;
	while ((ret = read(fd, cur_line, 16)) > 0)
	{
		cur_line[ret] = '\0';
		printed_symbols += ret;
		if (!line_equal_to_prev(cur_line, ret))
		{
			if (prev_line_is_equal)
			{
				buf_add_strn("*\n", 2);
				prev_line_is_equal = FALSE;
			}
			print_total_symbols(printed_symbols);
			print_line(cur_line, (ret + 1) & ~1);
		}
		else
			prev_line_is_equal = TRUE;
	}
}
