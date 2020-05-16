    #include <stdio.h>


#include "byte_tokenizer.h"
#include "byte_tokenizer_utils.h"

static int			byteline_lenght(const t_byteline *byteline)
{
	const int	tokens_count = vec_size((t_vector)&byteline->bytetokens);
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
								const t_vector_token tokens,
								int bytes_before)
{
	const int	tokens_count = vec_size((t_vector)&tokens);
	int			cur_token;
	t_label		label;
	t_byteline	byteline;

	label.bytes_before = bytes_before;
	cur_token = 0;
	while (cur_token < tokens_count && tokens[cur_token].type == LABEL)
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

// static void print(t_vector_label labels)
// {
// 	for (int i = 0; i < vec_size(&labels); ++i) {
// 		printf("NAME:  %s\n", labels[i].name);
// 		printf("BYTES: %d\n", labels[i].bytes_before);
// 	}
// }

t_vector_byteline	byte_tokenizer(const t_vector_token *tokens)
{
	const int			lines_count = vec_size(&tokens);
	int					line;
	t_vector_byteline	bytelines;
	t_vector_label		labels_list;
	int					bytes_before;

	bytelines = vec_create(lines_count, sizeof(t_byteline));
	labels_list = vec_create(50, sizeof(t_label));
	bytes_before = 0;
	line = 2;		// cause 0 - name and 1 - comment
	while (line < lines_count)
	{
		if (add_byteline(&bytelines, &labels_list, tokens[line], bytes_before))
			bytes_before +=
						byteline_lenght(&bytelines[vec_size(&bytelines) - 1]);
		// printf("line %d ok\n", line);
		line += 1;
	}
	// print(labels_list);
	fill_jumps(bytelines, labels_list);
	vec_destroy(&labels_list);
	return (bytelines);
}
