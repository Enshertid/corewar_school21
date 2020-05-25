/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 22:39:02 by user              #+#    #+#             */
/*   Updated: 2020/05/25 22:47:21 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include "token.h"

enum	e_file_status
{
	FILE_OK,
	FILE_EMPTY,
	FILE_NO_FINAL_NEWLINE
};

typedef enum e_file_status	t_file_status;

typedef struct		s_file
{
	const char		*name;
	int				fd;
	t_vector_char	*lines;
	t_vector_char	*bytecode;
	t_vector_token	*tokens;
	t_file_status	status;
}					t_file;

#endif
