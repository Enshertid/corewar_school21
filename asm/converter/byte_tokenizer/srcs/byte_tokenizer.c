#include "byte_tokenizer.h"
#include "byte_tokenizer_utils.h"

               #include <stdio.h>

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

static int			convert_to_byteline(t_byteline *byteline,
										  const t_vector_token *tokens,
										  int cur_line)
{
	const int	lines_count = vec_size(&tokens);
	int			cur_token;
	int			tokens_count;

	byteline->labels = vec_create(2, sizeof(char*));
	while (cur_line < lines_count)
	{
		tokens_count = vec_size((t_vector)&tokens[cur_line]);
		cur_token = 0;
		while (cur_token < tokens_count)
		{
			if (tokens[cur_line][cur_token].type == LABEL)
				vec_pushback(&byteline->labels, &tokens[cur_line][cur_token].value);
			else
				break ;
			cur_token += 1;
		}
		if (cur_token == tokens_count)
			cur_line += 1;
		else
		{
			byteline->bytetokens = vec_create(4, sizeof(t_byte_token));
			add_command(byteline, tokens[cur_line], cur_token);
			add_args(byteline, tokens[cur_line], cur_token);
			break ;
		}
	}
	return (cur_line);
}

static void print(const t_vector_byteline bytelines)
{
	for (int line = 0; line < vec_size((t_vector)&bytelines); ++line) {
		t_byteline *bline = &bytelines[line];
		if (vec_size(&bline->labels))
		{
			printf("LABELS:        ");
			for (int i = 0; i < vec_size(&bline->labels); ++i) {
				printf("%s ", bline->labels[i]);
			}
			printf("\n");
		}
		printf("COMMAND:       %s\n", bline->bytetokens[0].token->value);
		char *str = num_to_bits(&bline->bytetokens[0].value, 4);
		printf("COMMAND VALUE: %s\n", str);
		free(str);
		printf("ARGS:          ");
		for (int i = 1; i < vec_size(&bline->bytetokens); ++i) {
			char *str = num_to_bits(&bline->bytetokens[i].value, bline->bytetokens[i].value_size);
			printf("[%s | %d | %s] ", bline->bytetokens[i].token->value, bline->bytetokens[i].value, str);
			free(str);
		}
		printf("\n\n-----------------------------------------\n\n");
	}
}

t_vector_byteline	byte_tokenizer(const t_vector_token *tokens)
{
	const int			lines_count = vec_size(&tokens);
	int					line;
	t_vector_byteline	bytelines;
	t_byteline			byteline;
	int					bytes_before;

	bytelines = vec_create(lines_count, sizeof(t_byteline));
	bytes_before = 0;
	line = 2;
	while (line < lines_count)
	{
		line = convert_to_byteline(&byteline, tokens, line);
		byteline.bytes_before = bytes_before;
		vec_pushback(&bytelines, &byteline);
		bytes_before += byteline_lenght(&byteline);
		line += 1;
	}
	fill_labels(bytelines);
	print(bytelines);
	return (bytelines);
}
