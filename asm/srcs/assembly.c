#include "assembler.h"
#include "converter.h"

static void	read_file(t_file *file)
{
	char	*line;
	bool	newline_exist;
	bool	final_newline_exist;

	int i = 0;
	final_newline_exist = false;
	file->lines = vec_create(80, sizeof(t_vector_char));
	while ((gnl(file->fd, &line, &newline_exist)) == GNL_OK)
	{
		i += 1;
		vec_pushback(&file->lines, &line);
		if (!useless_line(line))
			final_newline_exist = newline_exist;
	}
	if (vec_size(&file->lines) == 0)
		file->status = FILE_EMPTY;
	else if (final_newline_exist == false)
		file->status = FILE_NO_FINAL_NEWLINE;
}

static void	error_handle(const t_file *file, t_validation	*val)
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

//  static void print(t_vector_char *lines, t_vector_token *tokens)
//  {
//  	const char types[10][15] = {
//  		"LABEL",
//  		"INSTRUCTION",
//  		"ARGUMENT",
//  		"SEPARATOR",
//  		"NAME",
//  		"COMMENT",
//  		"UNKNOWN",
//  		"EMPTY"
//  	};

//  	for (int row = 0; row < vec_size(&tokens); ++row)
//  	{
//  		printf("Line %d: %s\n", row, lines[row]);
//  		printf("Tokens:\n");
//  		for (int col = 0; col < vec_size(&tokens[row]); ++col) {
//  			printf("\tType: %s, value: \"%s\"\n", types[tokens[row][col].type],
//  											tokens[row][col].value);
//  		}
//  		printf("\n");
//  	}
//  }

void		assembly(t_file *file, t_validation	*validation)
{
	file->bytecode = NULL;
	file->copy = NULL;
	file->lines = NULL;
	file->tokens = NULL;
	file->status = FILE_OK;
	read_file(file);
	file->copy = vec_copy(&file->lines, false);
	if (file->status != FILE_OK)
		error_handle(file, validation);
	else
	{
		file->tokens = tokenizer(file->lines, validation);
		// print(file->copy, file->tokens);
		ft_check_labels(file->tokens, validation);
		ft_check_sizes(file->tokens, validation);
		ft_check_instructions(file->tokens, validation);
		if (!ft_any_error(validation))
		{
			file->bytecode = convert_to_bytecode(file->tokens);
			write_to_file(file, file->bytecode);
		}
	}
	free_file(file);
}
