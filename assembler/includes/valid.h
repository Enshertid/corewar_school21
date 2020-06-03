/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 15:21:15 by jgroleo           #+#    #+#             */
/*   Updated: 2020/05/24 12:58:18 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALID_H
# define VALID_H

typedef struct			s_validation
{
	int					have_instructions;
	int					name;
	int					comment;
	int					no_n_start;
	int					no_c_start;
	char				**lines;
	int					*line_index;
	int					error;
	int					trash_aft_name;
	int					dbl_n;
	int					dbl_c;
	int					no_newline_empty;
	int					not_file;
	int					extr;
	size_t				lines_count;
}						t_validation;

typedef struct			s_check_args
{
	int					i;
	char				*instr;
	char				**arg;
	int					col;
}						t_check_args;

#endif
