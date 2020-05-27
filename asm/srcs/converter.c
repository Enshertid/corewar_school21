/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:18:18 by user              #+#    #+#             */
/*   Updated: 2020/05/27 18:56:53 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "byte_tokenizer.h"
#include "converter_utils.h"
#include "converter.h"

static void		destroy_bytelines(t_vector_byteline lines)
{
	const int	lines_count = vec_size(&lines);
	int			line;

	line = 0;
	while (line < lines_count)
	{
		vec_destroy(&lines[line].bytetokens);
		line += 1;
	}
	vec_destroy(&lines);
}

t_vector_char	*convert_to_bytecode(t_vector_token *tokens)
{
	t_vector_byteline	bytelines;
	t_vector_char		*bytecode;

	bytelines = byte_tokenizer(tokens);
	bytecode = generate_bytecode(bytelines);
	destroy_bytelines(bytelines);
	return (bytecode);
}
