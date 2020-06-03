/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_bytecode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 14:16:14 by user              #+#    #+#             */
/*   Updated: 2020/05/25 22:26:06 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converter_utils.h"

static int		count_byteline_len(t_byte_token *tokens,
									int tokens_count)
{
	int			token;
	int			len;

	len = 0;
	token = 0;
	while (token < tokens_count)
	{
		len += tokens[token].value_size;
		token += 1;
	}
	return (len);
}

static void		big_gen(t_vector_char bytecode,
						t_byte_token *tokens,
						int tokens_count)
{
	int			cur_token;
	int			pos;
	char		*value_bytes;

	cur_token = 0;
	pos = 0;
	while (cur_token < tokens_count)
	{
		value_bytes = (char*)&tokens[cur_token].value;
		if (tokens[cur_token].value_size == 4)
		{
			bytecode[pos++] = value_bytes[0];
			bytecode[pos++] = value_bytes[1];
		}
		if (tokens[cur_token].value_size > 1)
			bytecode[pos++] = value_bytes[2];
		bytecode[pos++] = value_bytes[3];
		cur_token += 1;
	}
}

static void		lit_gen(t_vector_char bytecode,
						t_byte_token *tokens,
						int tokens_count)
{
	int			cur_token;
	int			pos;
	char		*value_bytes;

	cur_token = 0;
	pos = 0;
	while (cur_token < tokens_count)
	{
		value_bytes = (char*)&tokens[cur_token].value;
		if (tokens[cur_token].value_size == 4)
		{
			bytecode[pos++] = value_bytes[3];
			bytecode[pos++] = value_bytes[2];
		}
		if (tokens[cur_token].value_size > 1)
			bytecode[pos++] = value_bytes[1];
		bytecode[pos++] = value_bytes[0];
		cur_token += 1;
	}
}

static char		*generate_line(t_byte_token *tokens)
{
	const int	tokens_count = vec_size(&tokens);
	const int	bytes = count_byteline_len(tokens, tokens_count);
	char		*bytecode;

	bytecode = vec_create(bytes, 1);
	vec_reserve(&bytecode, bytes);
	if (bytes_order() == FT_LITTLE_ENDIAN)
		lit_gen(bytecode, tokens, tokens_count);
	else
		big_gen(bytecode, tokens, tokens_count);
	return (bytecode);
}

t_vector_char	*generate_bytecode(t_vector_byteline bytelines)
{
	const int		lines_count = vec_size(&bytelines);
	t_vector_char	*bytecode;
	char			*bytecode_line;
	int				line;

	bytecode = vec_create(lines_count, sizeof(char*));
	line = 0;
	while (line < lines_count)
	{
		bytecode_line = generate_line(bytelines[line].bytetokens);
		vec_pushback(&bytecode, &bytecode_line);
		line += 1;
	}
	return (bytecode);
}
