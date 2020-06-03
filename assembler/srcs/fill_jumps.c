/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_jumps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 22:31:16 by user              #+#    #+#             */
/*   Updated: 2020/05/25 22:32:59 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "byte_tokenizer_utils.h"

static const t_label	*find_label(const char *label_name,
									t_vector_label labels)
{
	const int	labels_count = vec_size(&labels);
	int			cur_label;

	cur_label = 0;
	while (cur_label < labels_count)
	{
		if (ft_strequ(label_name, labels[cur_label].name))
			return (&labels[cur_label]);
		cur_label += 1;
	}
	return (NULL);
}

static const char		*is_label_link(const t_token *arg)
{
	int pos;

	if (arg->value[0] == DIRECT_CHAR)
		pos = 1;
	else
		pos = 0;
	if (arg->value[pos] == LABEL_CHAR)
		return (arg->value + pos + 1);
	else
		return (NULL);
}

static void				fill_label_links(t_byteline *byteline,
										t_vector_label labels)
{
	const int		tokens_count = vec_size(&byteline->bytetokens);
	int				cur_token;
	const t_label	*label;
	const char		*label_name;
	t_byte_token	*bytetoken;

	cur_token = 0;
	while (cur_token < tokens_count)
	{
		label_name = is_label_link(byteline->bytetokens[cur_token].token);
		if (label_name)
		{
			label = find_label(label_name, labels);
			bytetoken = &byteline->bytetokens[cur_token];
			bytetoken->value = label->bytes_before - byteline->bytes_before;
			if (bytetoken->value_size == 2)
				bytetoken->value = (int16_t)bytetoken->value;
		}
		cur_token += 1;
	}
}

void					fill_jumps(t_vector_byteline bytelines,
									t_vector_label labels)
{
	const int	lines_count = vec_size(&bytelines);
	int			line;

	line = 0;
	while (line < lines_count)
	{
		fill_label_links(&bytelines[line], labels);
		line += 1;
	}
}
