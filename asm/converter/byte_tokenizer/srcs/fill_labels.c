#include "byte_tokenizer_utils.h"

static const t_byteline	*find_label(const char *label_name,
									const t_vector_byteline bytelines,
									int lines_count)
{
	int	line;
	int	label;
	int	labels_count;

	line = 0;
	while (line < lines_count)
	{
		labels_count = vec_size(&bytelines[line].labels);
		if (labels_count != 0)
		{
			label = 0;
			while (label != labels_count)
			{
				if (ft_strequ(label_name, bytelines[line].labels[label]))
					return (&bytelines[line]);
				label += 1;
			}
		}
		line += 1;
	}
	return (NULL);
}

static const char	*get_label_name(const t_token *token)
{
	int pos;

	pos = 0;
	if (token->value[pos] == DIRECT_CHAR)
		pos += 1;
	if (token->value[pos] == LABEL_CHAR)
		return (token->value + pos + 1);
	else
		return (NULL);
}

static void		fill_label_links(t_byteline *byteline,
								const t_vector_byteline bytelines,
								int lines_count)
{
	const int			tokens_count = vec_size(&byteline->bytetokens);
	int					token;
	const t_byteline	*labelpos;
	const char			*label_name;

	token = 1;
	while (token < tokens_count)
	{
		label_name = get_label_name(byteline->bytetokens[token].token);
		if (label_name != NULL)
		{
			labelpos = find_label(label_name, bytelines, lines_count);
			byteline->bytetokens[token].value = labelpos->bytes_before - byteline->bytes_before;
			if (byteline->bytetokens[token].value_size == 2)
				byteline->bytetokens[token].value = (int16_t)byteline->bytetokens[token].value;
		}
		token += 1;
	}
}

void			fill_labels(t_vector_byteline bytelines)
{
	const int	lines_count = vec_size(&bytelines);
	int			line;

	line = 0;
	while (line < lines_count)
	{
		fill_label_links(&bytelines[line], bytelines, lines_count);
		line += 1;
	}
}