/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 13:01:16 by user              #+#    #+#             */
/*   Updated: 2020/05/05 13:11:36 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/token_determinator.h"

const char		g_instructions[16][6] = {
	"live", "ldi", "add", "sub", "and", "xor", "lfork",
	"ld", "fork", "sti", "lldi", "aff", "or", "st", "lld", "zjmp"
};
const size_t	g_instructions_lenghts[16] = {
	4, 3, 3, 3, 3, 3, 5, 2, 4, 3, 4, 3, 2, 2, 3, 4
};

bool	is_instruction(const char **lineptr, t_token *token, t_validation	*val)
{
	const char	*line = *lineptr;
	size_t		iter;

	iter = 0;
	while (iter < 16)
	{
		if (ft_strnequ(line, g_instructions[iter],
						g_instructions_lenghts[iter]))
		{
			if (val->no_n_start == 0 && val->name == 0)
			{
				val->no_n_start = 1;
				val->error = 1;
				warning_add(ERROR, 1, "no name before code.");
			}
			if (val->no_c_start == 0 && val->comment == 0)
			{
				val->no_c_start = 1;
				val->error = 1;
				warning_add(ERROR, 1, "no comment before code.");
			}
			val->have_instructions = 1; // флаг для проверки файла на наличие инструкций
			token->type = INSTRUCTION;
			token->value = ft_strdup(g_instructions[iter]);
			*lineptr += g_instructions_lenghts[iter];
			return (true);
		}
		++iter;
	}
	return (false);
}
