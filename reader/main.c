/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 17:53:23 by user              #+#    #+#             */
/*   Updated: 2020/04/04 12:46:18 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

static void	usage(void)
{
	write(1, "usage: ./reader [filename]\n", 27);
}

int			main(int argc, char **argv)
{
	if (argc == 2)
	{
		warning_create();
		print(argv[1]);
		warning_print();
		warning_destroy();
	}
	else
		usage();
	return (0);
}
