/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 13:01:16 by user              #+#    #+#             */
/*   Updated: 2020/05/29 22:43:20 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token_determinator.h"

const char		g_instructions[16][6] = {
	"live", "ldi", "add", "sub", "and", "xor", "lfork",
	"ld", "fork", "sti", "lldi", "aff", "or", "st", "lld", "zjmp"
};
const size_t	g_instructions_lenghts[16] = {
	4, 3, 3, 3, 3, 3, 5, 2, 4, 3, 4, 3, 2, 2, 3, 4
};

static void	validate(t_validation *val, t_token *token, const char **lineptr,
				size_t iter)
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
	val->have_instructions = 1;
	token->type = INSTRUCTION;
	token->value = ft_strdup(g_instructions[iter]);
	*lineptr += g_instructions_lenghts[iter];
}

static bool	instr_equ(const char *name, const char *instruction,
						size_t symbols)
{
	while (symbols)
	{
		if (*name != *instruction)
			return (false);
		name += 1;
		instruction += 1;
		symbols -= 1;
	}
	return (true);
}

bool		is_instruction(const char **lineptr, t_token *token,
							t_validation *val)
{
	const char	*line = *lineptr;
	size_t		iter;

	iter = 0;
	while (iter < 16)
	{
		if (instr_equ(line, g_instructions[iter],
						g_instructions_lenghts[iter]))
		{
			validate(val, token, lineptr, iter);
			return (true);
		}
		++iter;
	}
	return (false);
}
