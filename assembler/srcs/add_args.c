/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:55:50 by user              #+#    #+#             */
/*   Updated: 2020/05/25 22:35:18 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "byte_tokenizer_utils.h"

static int			determine_dir_size(const char *command)
{
	if (ft_strequ(command, "ldi") || ft_strequ(command, "zjmp") ||
		ft_strequ(command, "sti") || ft_strequ(command, "fork") ||
		ft_strequ(command, "lldi") || ft_strequ(command, "lfork"))
		return (2);
	else
		return (4);
}

static uint8_t		determine_arg(const t_token *arg)
{
	if (arg->value[0] == DIRECT_CHAR)
		return (DIR_CODE);
	else if (arg->value[0] == 'r')
		return (REG_CODE);
	else
		return (IND_CODE);
}

static int32_t		get_arg_value(const t_token *arg)
{
	int pos;

	pos = 0;
	if (arg->value[pos] == '%')
		pos += 1;
	if (arg->value[pos] == 'r')
		pos += 1;
	return (ft_atoi(arg->value + pos));
}

static t_byte_token	get_arg(t_token *token, int dir_size)
{
	const uint8_t	arg_type = determine_arg(token);
	t_byte_token	byte_token;

	byte_token.token = token;
	byte_token.value = get_arg_value(token);
	if (arg_type == DIR_CODE)
		byte_token.value_size = dir_size;
	else if (arg_type == IND_CODE)
		byte_token.value_size = 2;
	else
		byte_token.value_size = 1;
	return (byte_token);
}

void				add_args(t_byteline *byteline,
							t_vector_token tokens, int pos)
{
	const int		tokens_count = vec_size(&tokens);
	const int		dir_size = determine_dir_size(tokens[pos].value);
	t_byte_token	arg_token;
	int				arg_num;

	pos += 1;
	arg_num = 1;
	while (arg_num <= 3 && pos < tokens_count)
	{
		arg_token = get_arg(tokens + pos, dir_size);
		vec_pushback(&byteline->bytetokens, &arg_token);
		pos += 2;
		arg_num += 1;
	}
}
