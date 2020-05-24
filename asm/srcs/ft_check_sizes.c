/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sizes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 15:21:15 by jgroleo           #+#    #+#             */
/*   Updated: 2020/05/24 12:58:18 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void		ft_large_n(t_validation *val)
{
	val->error = 1;
	warning_add(ERROR, 1, "too large length of name.");
}

void		ft_large_c(t_validation *val)
{
	val->error = 1;
	warning_add(ERROR, 1, "too large length of comment.");
}

void		ft_check_sizes(t_vector_token *tokens, t_validation *val)
{
	int	row;
	int	col;

	row = 0;
	while (row < vec_size(&tokens))
	{
		col = 0;
		while (col < vec_size(&tokens[row]))
		{
			if (tokens[row][col].type == 4)
			{
				if ((int)ft_strlen(tokens[row][col].value) > PROG_NAME_LENGTH)
					ft_large_n(val);
			}
			else if (tokens[row][col].type == 5)
			{
				if ((int)ft_strlen(tokens[row][col].value) > COMMENT_LENGTH)
					ft_large_c(val);
			}
			col++;
		}
		row++;
	}
}

void		ft_nonexist_l(t_validation *val, char **labels, int i)
{
	warning_add(ERROR, 3, "Nonexistent label \"", labels[i], "\".");
	val->error = 1;
}

bool		is_empty(const char **str, t_token *token)
{
	bool		argument;

	argument = false;
	if (useless_line(*str) == true)
	{
		argument = true;
		token->type = EMPTY;
		token->value = ft_strndup("\0", 1);
		*str = *str + 1;
		return (argument);
	}
	return (argument);
}
