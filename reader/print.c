/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 16:17:04 by user              #+#    #+#             */
/*   Updated: 2020/03/31 16:17:05 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "reader.h"

void					print(const char *filename)
{
	const int	fd = open(filename, O_RDONLY);

	buf_create(1, 2048);
	if (fd >= 0)
	{
		print_hex(fd);
		close(fd);
	}
	else
		warning_add(ERROR, 2, "Can\'t open file: ", filename);
	buf_flush();
	buf_destroy();
}
