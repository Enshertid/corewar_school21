#include "assembler.h"
#include "converter.h"

static bool	useless_line(const char *line)
{
	while (*line && (*line == ' ' || *line == '\t'))
		++line;
	if (!*line || *line == COMMENT_CHAR || *line == ';')
		return (true);
	else
		return (false);
}

static void	read_file(t_file *file)
{
	char	*line;
	bool	newline_exist;
	bool	last_line;

	int i = 0;
	file->lines = vec_create(80, sizeof(t_vector_char));
	while ((gnl(file->fd, &line, &last_line)) == GNL_OK)
	{
		i += 1;
		if (useless_line(line))
			free(line);
		else
		{
			vec_pushback(&file->lines, &line);
			newline_exist = last_line;
		}
	}
	if (vec_size(&file->lines) == 0)
		file->status = FILE_EMPTY;
	else if (newline_exist == false)
		file->status = FILE_NO_FINAL_NEWLINE;
}

static void	free_file(t_file *file)
{
	const size_t	lines_amount = vec_size(&file->lines);
	size_t			line;

	line = 0;
	while (line < lines_amount)
	{
		if (file->lines[line][0] != '\0') // иначе фришится то, что не замолочено (.name / .comment == '\0')
		{
			free(file->lines[line]);
		}
		line += 1;
	}
	vec_destroy(&file->lines);
}

static void	error_handle(const t_file *file)
{
	if (file->status == FILE_NO_FINAL_NEWLINE)
		warning_add(ERROR, 3, "File \"", file->name,
							"\" haven\'t final newline");
	else if (file->status == FILE_EMPTY)
		warning_add(ERROR, 3, "File \"", file->name, "\" is empty");
}



 static void destroy_tokens(t_vector_token *tokens)
 {
	 for (int i = 0; i < vec_size(&tokens); ++i) {
		 for (int j = 0; j < vec_size(&tokens[i]); ++j) {
			 free(tokens[i][j].value);
		 }
		 vec_destroy(&tokens[i]);
	 }
	 vec_destroy(&tokens);
 }

 static void destroy_bytecode(t_vector_char *bytecode)
 {
	 for (int i = 0; i < vec_size(&bytecode); ++i) {
		 vec_destroy(&bytecode[i]);
	 }
	 vec_destroy(&bytecode);
 }

//  static void print(t_vector_char *lines, t_vector_token *tokens)
//  {
//  	const char types[9][15] = {
//  		"LABEL",
//  		"INSTRUCTION",
//  		"ARGUMENT",
//  		"SEPARATOR",
//  		"NAME",
//  		"COMMENT",
//  		"UNKNOWN"
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
	t_vector_char *bytecode;
	file->status = FILE_OK;
	read_file(file);
	if (file->status != FILE_OK)
		error_handle(file);
	else
	{
		file->tokens = tokenizer(file->lines, validation);
		//  print(file->lines, file->tokens);
		ft_check_labels(file->tokens, validation);
		ft_check_sizes(file->tokens, validation);
		ft_check_instructions(file->tokens, validation);
		// tokens_analysis(file);
//		if (file->status == FILE_OK)
//		{
		if (validation->error == 0)
		{
			// printf("NAME: %s\nCOMMENT:\"\n%s\"\n", file->tokens[0][0].value, file->tokens[1][0].value);
			bytecode = convert_to_bytecode(file->tokens);
			write_to_file(file, bytecode);
			destroy_bytecode(bytecode);
		}
		destroy_tokens(file->tokens);
		// validation->comment = 0;
		// validation->name = 0;
	}
	free_file(file);
}
