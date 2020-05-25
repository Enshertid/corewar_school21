/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembly.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 22:28:46 by user              #+#    #+#             */
/*   Updated: 2020/05/25 22:32:01 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"
#include "converter.h"

static void		read_file(t_file *file)
{
	char	*line;
	bool	final_newline_exist;

	file->lines = vec_create(80, sizeof(t_vector_char));
	while ((gnl(file->fd, &line, &final_newline_exist)) == GNL_OK)
	{
		vec_pushback(&file->lines, &line);
	}
	if (vec_size(&file->lines) == 0)
		file->status = FILE_EMPTY;
	else if (final_newline_exist == false)
		file->status = FILE_NO_FINAL_NEWLINE;
}

static void		free_file(t_file *file)
{
	const size_t	lines_amount = vec_size(&file->lines);
	const size_t	tokens_amount = vec_size(&file->tokens);
	size_t			line;
	size_t			token_line;
	int				i;

	line = 0;
	while (line < lines_amount)
	{
		if (file->lines[line][0] != '\0')
			free(file->lines[line]);
		line += 1;
	}
	vec_destroy(&file->lines);
	token_line = 0;
	while (token_line < tokens_amount)
	{
		i = -1;
		while (++i < vec_size(&file->tokens[token_line]))
			free(file->tokens[token_line][i].value);
		vec_destroy(&file->tokens[token_line]);
		token_line += 1;
	}
	vec_destroy(&file->tokens);
}

static void		error_handle(const t_file *file, t_validation *val)
{
	if (file->status == FILE_NO_FINAL_NEWLINE)
	{
		warning_add(ERROR, 3, "File \"", file->name,
					"\" haven\'t final newline");
		val->no_newline_empty = 1;
	}
	else if (file->status == FILE_EMPTY)
	{
		warning_add(ERROR, 3, "File \"", file->name, "\" is empty");
		val->no_newline_empty = 1;
	}
}

/*
** static void print(t_vector_char *lines, t_vector_token *tokens)
** {
** 	const char types[10][15] = {
** 		"LABEL",
** 		"INSTRUCTION",
** 		"ARGUMENT",
** 		"SEPARATOR",
** 		"NAME",
** 		"COMMENT",
** 		"UNKNOWN",
** 		"EMPTY"
** 	};
**
** 	for (int row = 0; row < vec_size(&tokens); ++row)
** 	{
** 		printf("Line %d: %s\n", row, lines[row]);
** 		printf("Tokens:\n");
** 		for (int col = 0; col < vec_size(&tokens[row]); ++col) {
** 			printf("\tType: %s, value: \"%s\"\n", types[tokens[row][col].type],
** 											tokens[row][col].value);
** 		}
** 		printf("\n");
** 	}
** }
*/

static void		destroy_bytecode(t_vector_char *bytecode)
{
	const int	lines = vec_size(&bytecode);
	int			line;

	line = 0;
	while (line < lines)
	{
		vec_destroy(&bytecode[line]);
		line += 1;
	}
}

void			assembly(t_file *file, t_validation *validation)
{
	t_vector_char *bytecode;

	file->status = FILE_OK;
	read_file(file);
	if (file->status != FILE_OK)
		error_handle(file, validation);
	else
	{
		file->tokens = tokenizer(file->lines, validation);
		ft_check_labels(file->tokens, validation);
		ft_check_sizes(file->tokens, validation);
		ft_check_instructions(file->tokens, validation);
		if (!ft_any_error(validation))
		{
			bytecode = convert_to_bytecode(file->tokens);
			write_to_file(file, bytecode);
			destroy_bytecode(bytecode);
		}
	}
	free_file(file);
}
