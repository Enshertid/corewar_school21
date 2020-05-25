/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:53:05 by user              #+#    #+#             */
/*   Updated: 2020/05/25 22:33:34 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "byte_tokenizer_utils.h"
#include "commands.h"

static uint8_t	get_command_code(const char *command)
{
	int i;

	i = 0;
	while (i < COMMANDS_COUNT)
	{
		if (ft_strequ(command, g_commands_list[i]))
			break ;
		i += 1;
	}
	return (g_commands_codes[i]);
}

static uint8_t	determine_arg(const t_token *arg)
{
	if (arg->value[0] == DIRECT_CHAR)
		return (DIR_CODE);
	else if (arg->value[0] == 'r')
		return (REG_CODE);
	else
		return (IND_CODE);
}

static uint8_t	build_args_byte(t_vector_token tokens, int pos)
{
	uint8_t	args_byte;

	args_byte = 0;
	args_byte |= ((determine_arg(tokens + pos)) << 6);
	pos += 2;
	if (pos < vec_size(&tokens))
		args_byte |= ((determine_arg(tokens + pos)) << 4);
	pos += 2;
	if (pos < vec_size(&tokens))
		args_byte |= ((determine_arg(tokens + pos)) << 2);
	return (args_byte);
}

void			add_command(t_byteline *byteline,
							t_vector_token tokens, int pos)
{
	const char		*command = tokens[pos].value;
	t_byte_token	byte_token;

	byte_token.token = tokens + pos;
	byte_token.value = get_command_code(command);
	byte_token.value_size = 1;
	if (!ft_strequ(command, "live") && !ft_strequ(command, "zjmp") &&
		!ft_strequ(command, "fork") && !ft_strequ(command, "lfork"))
	{
		byte_token.value <<= 8;
		byte_token.value |= (build_args_byte(tokens, pos + 1));
		byte_token.value_size += 1;
	}
	vec_pushback(&byteline->bytetokens, &byte_token);
}
