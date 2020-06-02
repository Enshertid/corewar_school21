/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enshertid <enshertid@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 22:25:22 by user              #+#    #+#             */
/*   Updated: 2020/06/03 01:28:40 by enshertid        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static void	usage(void)
{
	write(1, "usage: ./asm [file]\n", 20);
}

static void	check_op_h(void)
{
	if (ft_strchr(LABEL_CHARS, LABEL_CHAR))
		ft_error("LABEL_CHAR exist in LABEL_CHARS", "check_op_h", 0);
	if (ft_strchr(LABEL_CHARS, SEPARATOR_CHAR))
		ft_error("SEPARATOR CHAR exist in LABEL_CHARS", "check_op_h", 0);
	if (ft_strchr(LABEL_CHARS, DIRECT_CHAR))
		ft_error("LABEL CHAR exist in LABEL_CHARS", "check_op_h", 0);
	if (REG_SIZE != 4)
		ft_error("REG_SIZE must be equal to 4", "check_op_h", 0);
	if (IND_SIZE != 2)
		ft_error("IND_SIZE must be equal to 2", "check_op_h", 0);
}

int			main(int argc, const char *const *argv)
{
	if (argc == 2)
	{
		check_op_h();
		if (ft_validation(argv) == 0)
			exit(0);
	}
	else
		usage();
	return (0);
}
