/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_tokenizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 22:18:58 by user              #+#    #+#             */
/*   Updated: 2020/05/27 18:59:20 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "byte_tokenizer.h"
#include "byte_tokenizer_utils.h"

static int			byteline_lenght(t_byteline *byteline)
{
	const int	tokens_count = vec_size(&byteline->bytetokens);
	int			cur_token;
	int			lenght;

	lenght = 0;
	cur_token = 0;
	while (cur_token < tokens_count)
	{
		lenght += byteline->bytetokens[cur_token].value_size;
		cur_token += 1;
	}
	return (lenght);
}

static bool			add_byteline(t_vector_byteline *bytelines,
								t_vector_label *labels_list,
								t_vector_token tokens,
								int bytes_before)
{
	const int	tokens_count = vec_size(&tokens);
	int			cur_token;
	t_label		label;
	t_byteline	byteline;

	label.bytes_before = bytes_before;
	cur_token = 0;
	while (cur_token < tokens_count && (tokens[cur_token].type == LABEL ||
										tokens[cur_token].type == EMPTY ||
										tokens[cur_token].type == NAME ||
										tokens[cur_token].type == COMMENT))
	{
		label.name = tokens[cur_token].value;
		vec_pushback(labels_list, &label);
		cur_token += 1;
	}
	if (cur_token == tokens_count)
		return (false);
	byteline.bytes_before = bytes_before;
	byteline.bytetokens = vec_create(4, sizeof(t_byte_token));
	add_command(&byteline, tokens, cur_token);
	add_args(&byteline, tokens, cur_token);
	vec_pushback(bytelines, &byteline);
	return (true);
}

t_vector_byteline	byte_tokenizer(t_vector_token *tokens)
{
	const int			lines_count = vec_size(&tokens);
	int					line;
	t_vector_byteline	bytelines;
	t_vector_label		labels_list;
	int					bytes_before;

	bytelines = vec_create(lines_count, sizeof(t_byteline));
	labels_list = vec_create(50, sizeof(t_label));
	bytes_before = 0;
	line = 0;
	while (line < lines_count)
	{
		if (add_byteline(&bytelines, &labels_list, tokens[line], bytes_before))
			bytes_before +=
						byteline_lenght(&bytelines[vec_size(&bytelines) - 1]);
		line += 1;
	}
	fill_jumps(bytelines, labels_list);
	vec_destroy(&labels_list);
	return (bytelines);
}
