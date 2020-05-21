/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 16:17:04 by user              #+#    #+#             */
/*   Updated: 2020/04/04 12:46:04 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include "reader.h"

static bool	is_dir(const char *filename)
{
	struct stat	statbuf;

	if (stat(filename, &statbuf) == 0)
	{
		if (S_ISDIR(statbuf.st_mode))
		{
			warning_add(ERROR, 3, "\"", filename, "\" is directory");
			return (true);
		}
	}
	return (false);
}

void			print(const char *filename)
{
	int	fd;

	if (is_dir(filename))
		return ;
	fd = open(filename, O_RDONLY);
	buf_create(1, 2048);
	if (fd >= 0)
	{
		print_hex(fd);
		close(fd);
	}
	else
		warning_add(ERROR, 3, "Can\'t open file \"", filename, "\"");
	buf_flush();
	buf_destroy();
}
