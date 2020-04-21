#include <stdio.h>
#include "token.h"

static t_bool		is_instruction(const char *str, size_t *skip,
									char **instruction)
{
	static char	instructions[16][6] = {
		"live", "ldi", "add", "sub", "and", "xor", "lld", "lfork",
		"ld", "fork", "sti", "lldi", "aff", "or", "st", "zjmp",
	};
	static char	instructions_lenghts[16] = {
		4, 3, 3, 3, 3, 3, 3, 5, 2, 4, 3, 4, 3, 2, 2, 4
	};
	size_t		iter;

	iter = 0;
	while (iter < 16)
	{
		if (ft_strnequ(str, instructions[iter], instructions_lenghts[iter]))
		{
			*instruction = instructions[iter];
			*skip = instructions_lenghts[iter];
			return (TRUE);
		}
		++iter;
	}
	return (FALSE);
}



static t_bool		is_argument(const char *line, size_t *skip)
{
	size_t			skip_symbols;

	skip_symbols = 0;
	if (*line == DIRECT_CHAR)
	{
		skip_symbols += 1;
		line += 1;
	}
	if (ft_isdigit(*line) || (line[0] == 'r' && ft_isdigit(line[1])))
	{
		if (line[0] == 'r')
		{
			skip_symbols += 1;
			line += 1;
		}
		while (ft_isdigit(*line))
		{
			skip_symbols += 1;
			line += 1;
		}
		*skip = skip_symbols;
		return (TRUE);
	}
	else if (line[0] == LABEL_CHAR && ft_strchr(LABEL_CHARS, line[1]))
	{
		skip_symbols += 1;
		line += 1;
		while (*line && ft_strchr(LABEL_CHARS, *line))
		{
			skip_symbols += 1;
			line += 1;
		}
		*skip = skip_symbols;
		return (TRUE);
	}
	else
		return (FALSE);
}

/*

bite:	zjmp

:bite

*/

static t_bool		is_label(const char *line, size_t *skip)
{
	size_t			skip_symbols;
	t_bool			name_exist;

	skip_symbols = 0;
	name_exist = FALSE;
	while (*line && ft_strchr(LABEL_CHARS, *line))
	{
		name_exist = TRUE;
		++line;
		++skip_symbols;
	}
	while (*line == ' ' || *line == '\t')
	{
		++line;
		++skip_symbols;
	}
	if (name_exist && *line == LABEL_CHAR)
	{
		*skip = skip_symbols + 1;
		return (TRUE);
	}
	else
		return (FALSE);
}

t_token				get_token(const char *line, size_t *skip)
{
	t_token			token;

	if (*line == SEPARATOR_CHAR)
	{
		token.type = SEPARATOR;
		token.value = ft_strdup(",");
		*skip = 1;
	}
	else if (is_instruction(line, skip, &token.value))
		token.type = INSTRUCTION;
	else if (is_label(line, skip))
	{
		token.type = LABEL;
		token.value = ft_strndup(line, *skip);
	}
	else if (is_argument(line, skip))
	{
		token.type = ARGUMENT;
		token.value = ft_strndup(line, *skip);
	}
	else
	{
		token.type = UNKNOWN;
		token.value = NULL;
		*skip = 0;
		while (*line && (*line != ' ' || *line != '\t'))
		{
			line += 1;
			*skip += 1;
		}
	}
	return (token);
}

t_vector_token		line_to_tokens(const char *line)
{
	t_vector_token	tokens;
	t_token			token;
	size_t			skip;

	tokens = vec_create(8, sizeof(t_token));
	while (*line)
	{
		while (*line && (*line == ' ' || *line == '\t'))
			++line;
		if (*line == COMMENT_CHAR)
			break ;
		token = get_token(line, &skip);
		vec_pushback(&tokens, &token);
		line += skip;
	}
	return (tokens);
}

static void print(t_vector_char *lines, t_vector_token *tokens)
{
	const char types[7][15] = {
		"LABEL",
		"CHAR_LABEL",
		"INSTRUCTION",
		"ARGUMENT",
		"CHAR_DIRECT",
		"SEPARATOR",
		"UNKNOWN"
	};

	for (size_t row = 0; row < vec_size(&tokens); ++row)
	{
		printf("Line %zu: %s\n", row, lines[row]);
		printf("Tokens:\n");
		for (size_t col = 0; col < vec_size(&tokens[row]); ++col) {
			printf("\tType: %s, value: \"%s\"\n", types[tokens[row][col].type],
											tokens[row][col].value);
		}
		printf("\n");
	}
}

t_vector_token		*tokenizer(t_vector_char *lines)
{
	const size_t	lines_amount = vec_size(&lines);
	size_t			iter;
	t_vector_token	*tokens;
	t_vector_token	tokens_line;

	tokens = vec_create(lines_amount, sizeof(t_vector_token));
	iter = 0;
	while (iter < lines_amount)
	{
		tokens_line = line_to_tokens(lines[iter]);
		vec_pushback(&tokens, &tokens_line);
		iter += 1;
		// printf("%zu ok\n", iter);
	}
	print(lines, tokens);
	return (tokens);
}
