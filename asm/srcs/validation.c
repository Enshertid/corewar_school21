#include "assembler.h"

#include <stdio.h> // DELETE

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;

	i = 0;
	while (s1[i] && s1[i] == s2[i] && n--)
		i++;
	if (n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	j = 0;
	i = 0;
	str = (char*)malloc((int)ft_strlen(s2) + (int)ft_strlen(s1) + 1);
	if (!str)
		return (NULL);
	while (s1[j])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}

int 	ft_check_closed_quote(char *str, t_validation *val)
{
	int 	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '"')
		{
//			printf ("str: %s, i: %d, len:%d\n", str, i, (int)ft_strlen(str));
			if (i == (int)ft_strlen(str) - 1) // проверка на то что после ковычек ничего нет типо "123"123""
				return (1);
			else
			{
				val->error = 1;
				return (0);
			}
		}
		i++;
	}
	return (0);
}

void	ft_check_one_arg(t_check_args *checker, t_validation *val, int row)
{
	if (ft_strcmp(checker->instr, "aff") == 0)
	{
		if (checker->arg[0][0] != 'r')
		{
			val->error = 1;
			warning_add(ERROR, 2, "wrong types of argument in line: ", ft_itoa_static(row + 1, 10));
//			printf("instr aff, arg is not REG\n");
		}
	}
	else if (ft_strcmp(checker->instr, "zjmp") == 0 || ft_strcmp(checker->instr, "live") == 0 ||
			ft_strcmp(checker->instr, "fork") == 0 || ft_strcmp(checker->instr, "lfork") == 0)
	{
		if (checker->arg[0][0] != '%')
		{
			val->error = 1;
			warning_add(ERROR, 2, "wrong types of argument in line: ", ft_itoa_static(row + 1, 10));
//			printf("instr zjmp/live/fork/lfork, arg is not REG\n");
		}
	}
	else
	{
		val->error = 1;
		warning_add(ERROR, 2, "wrong types of argument in line: ", ft_itoa_static(row + 1, 10));
//		printf ("some instr with wrong 1 arg\n");
	}
}

void	ft_check_two_arg(t_check_args *checker, t_validation *val, int row)
{
	if (ft_strcmp(checker->instr, "st") == 0)
	{
		if (checker->arg[0][0] != 'r' || checker->arg[1][0] == '%')
		{
			val->error = 1;
			warning_add(ERROR, 2, "wrong types of argument in line: ", ft_itoa_static(row + 1, 10));
//			printf("instr st, arg 1 is not REG or arg 2 is T_DIR\n");
		}
	}
	else if (ft_strcmp(checker->instr, "ld") == 0 || ft_strcmp(checker->instr, "lld") == 0)
	{
		if (checker->arg[0][0] == 'r' || checker->arg[1][0] != 'r')
		{
			val->error = 1;
			warning_add(ERROR, 2, "wrong types of argument in line: ", ft_itoa_static(row + 1, 10));
//			printf("instr ld/lld, arg 1 is REG or arg 2 isn't REG\n");
		}
	}
	else
	{
		val->error = 1;
		warning_add(ERROR, 2, "wrong types of argument in line: ", ft_itoa_static(row + 1, 10));
//		printf ("some instr with wrong 2 arg\n");
	}
}

void	ft_check_three_arg(t_check_args *checker, t_validation *val, int row)
{
	if (ft_strcmp(checker->instr, "add") == 0 || ft_strcmp(checker->instr, "sub") == 0)
	{
		if (checker->arg[0][0] != 'r' || checker->arg[1][0] != 'r' || checker->arg[2][0] != 'r')
		{
			val->error = 1;
			warning_add(ERROR, 2, "wrong types of argument in line: ", ft_itoa_static(row + 1, 10));
//			printf("instr add/sub, args not REG\n");
		}
	}
	else if (ft_strcmp(checker->instr, "and") == 0 || ft_strcmp(checker->instr, "or") == 0 ||
	ft_strcmp(checker->instr, "xor") == 0)
	{
		if (checker->arg[2][0] != 'r')
		{
			val->error = 1;
			warning_add(ERROR, 2, "wrong types of argument in line: ", ft_itoa_static(row + 1, 10));
//			printf("instr and/or/xor, arg 3 isn't REG\n");
		}
	}
	else if (ft_strcmp(checker->instr, "ldi") == 0 || ft_strcmp(checker->instr, "lldi") == 0)
	{
		if (checker->arg[1][0] == ':' || ft_isdigit(checker->arg[1][0]) == 1 || checker->arg[2][0] != 'r')
		{
			val->error = 1;
			warning_add(ERROR, 2, "wrong types of argument in line: ", ft_itoa_static(row + 1, 10));
//			printf("instr ldi/lldi, arg 2 is IND or 3 not REG\n");
		}
	}
	else if (ft_strcmp(checker->instr, "sti") == 0)
	{
		if (checker->arg[0][0] != 'r' || checker->arg[2][0] == ':' || ft_isdigit(checker->arg[2][0]) == 1)
		{
			val->error = 1;
			warning_add(ERROR, 2, "wrong types of argument in line: ", ft_itoa_static(row + 1, 10));
//			printf("instr ldi/lldi, arg 2 is IND or 3 not REG\n");
		}
	}
	else
	{
		val->error = 1;
		warning_add(ERROR, 2, "wrong types of argument in line: ", ft_itoa_static(row + 1, 10));
//		printf ("some instr with wrong 3 arg\n");
	}
}

void	ft_check_arg(t_check_args *checker, t_validation *val, int row)
{
	int		i;

	i = checker->i;
	if (i == 0) // если 1 арг
		ft_check_one_arg(checker, val, row);
	else if (i == 1) // если 2 арг
		ft_check_two_arg(checker, val, row);
	else if (i == 2) // если 3 арг
		ft_check_three_arg(checker, val, row);
	else
	{
		warning_add(ERROR, 2, "лишняя проверка? too many arguments in line: ", ft_itoa_static(row + 1, 10)); // ЛИШНЯЯ ПРОВЕРКА
		val->error = 1;
	}
	while (i > -1) // ЧТО ЭТО? =)
	{
		i--;
	}
}

void	ft_check_instructions(t_vector_token *tokens, t_validation *val)
{
	int 			row;
	int 			col;
	int 			i;
	t_check_args	*checker;

	checker = (t_check_args*)malloc(sizeof(t_check_args));
	checker->arg = (char**)malloc(sizeof(char*) * 3);
	row = 0;
	while (row < vec_size(&tokens))
	{
		col = 0;
		while (col < vec_size(&tokens[row]))
		{
			if (tokens[row][col].type == 1)
			{
//				printf("Instr:%s; ", tokens[row][col].value);
				checker->instr = tokens[row][col].value;
				col++;
				i = 0; // сделать -1 и ++ в цикле
				while (col < vec_size(&tokens[row]))
				{
					if (tokens[row][col].type == 2)
					{
						checker->i = i;
						checker->arg[i] = ft_strdup(tokens[row][col].value);
						i++;
					}
					col++;
				}
				ft_check_arg(checker, val, row);
//				printf("\n");
			}
			col++;
		}
		col--;
		col--;
		if (tokens[row][col].type != 2 && tokens[row][0].type != 4 && tokens[row][0].type != 5 && col != -1) // проверка что в конце аргумент стоит, добавить когда на строке один LABEL
		{
			val->error = 1;
			warning_add(ERROR, 3, "last token in line ", ft_itoa_static(row + 1, 10), " is not argument. Лишняя проверка?"); // ЛИШНЯЯ ПРОВЕРКА?
		}
		row++;
	}
	free(checker->arg);
}

void 	ft_check_sizes(t_vector_token *tokens, t_validation *val)
{
	int 	row;
	int 	col;

	row = 0;
	while (row < vec_size(&tokens))
	{
		col = 0;
		while (col < vec_size(&tokens[row]))
		{
			if (tokens[row][col].type == 4)
			{
				if ((int)ft_strlen(tokens[row][col].value) > PROG_NAME_LENGTH)
				{
					val->error = 1;
					warning_add(ERROR, 1, "too large length of name.");
				}
			}
			else if (tokens[row][col].type == 5)
			{
				if ((int)ft_strlen(tokens[row][col].value) > COMMENT_LENGTH)
				{
					val->error = 1;
					warning_add(ERROR, 1, "too large length of comment.");
				}
			}
			col++;
		}
		row++;
	}
}

void	ft_check_string(t_vector_token *tokens, int row, t_validation *val)
{
	int 	col;
	int		prev;

	if (vec_size(&tokens[row]) > 6 || (vec_size(&tokens[row]) == 1 && tokens[row][0].type != 0 &&
			tokens[row][0].type != 4 && tokens[row][0].type != 5))
	{
		val->error = 1;
		warning_add(ERROR, 2, "ft_check_string Syntax error in line: ", ft_itoa_static(row + 1, 10));
	}
	else
	{
		col = 0;
		if (tokens[row][0].type == 0 || tokens[row][0].type == 4 || tokens[row][0].type == 5) // скип лейбл/name/comment на первом месте
			col++;
		if (col < vec_size(&tokens[row]))
		{
			if (tokens[row][col].type != 1) // если не инструкция
			{
				val->error = 1;
				warning_add(ERROR, 2, "wrong tokens in line: ", ft_itoa_static(row + 1, 10));
			}
			else
			{
				col++;
				if (tokens[row][col].type != 2 && tokens[row][0].type != 4 && tokens[row][0].type != 5) // если не арг
				{
					val->error = 1;
					warning_add(ERROR, 2, "wrong tokens in line: ", ft_itoa_static(row + 1, 10));
				}
				else
				{
					col++;
					prev = 2; // 2-арг, 3-сеп
					while (col < vec_size(&tokens[row]))
					{
						if (prev == 2 && tokens[row][col].type == 3)
						{
							prev = 3;
							col++;
						}
						else if (prev == 3 && tokens[row][col].type == 2)
						{
							prev = 2;
							col++;
						}
						else
						{
							val->error = 1;
							warning_add(ERROR, 2, "wrong tokens order in line: ", ft_itoa_static(row + 1, 10));
							break;
						}
					}
				}
			}
		}
	}
}

void	ft_check_labels(t_vector_token *tokens, t_validation *val)
{
	int 	row;
	int 	col;
	char 	**labels;
	int 	i;
	char	*line;

	i = 0;
	labels = (char**)malloc(vec_size(&tokens) * sizeof(char*));
	row = 0;
	while (row < vec_size(&tokens))
	{
		col = 0;
		if (tokens[row][col].type != 6) // не чекаем строку с дабл именем/коментом
			ft_check_string(tokens, row, val);
		while (col < vec_size(&tokens[row]))
		{
			if (tokens[row][col].type == 2 && tokens[row][col].value[0] == ':')
			{
				line = tokens[row][col].value;
				line += 1;
				labels[i] = ft_strdup(line);
				i++;
			}
			if (tokens[row][col].type == 2 && tokens[row][col].value[1] == ':')
			{
				line = tokens[row][col].value;
				line += 2;
				labels[i] = ft_strdup(line);
				i++;
			}
			col++;
		}
		row++;
	}

	int 	flag;
	while (--i > -1)
	{
		flag = 0;
		row = 0;
		while (row < vec_size(&tokens))
		{
			if (tokens[row][0].type == 0 && ft_strcmp(labels[i], tokens[row][0].value) == 0)
				flag = 1;
			row++;
		}
		if (flag == 0)
		{
			warning_add(ERROR, 4, "Nonexistent label \"", labels[i], "\" in line: ", ft_itoa_static(row, 10));
			val->error = 1;
		}
		free(labels[i]);
	}
	free(labels);
}

bool	is_name(const char **str, t_token *token, t_validation	*val)
{
	bool		argument;

	argument = false;
	if (ft_strncmp(val->lines[*val->line_index], NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) == 0 && val->lines[*val->line_index][ft_strlen(NAME_CMD_STRING)] == ' ')
	{
		if (val->name == 1) //проверка на дубль
		{
			warning_add(ERROR, 2, "is_name Double name in line ", ft_itoa_static(*val->line_index + 1, 10)); //создать новый флаг чтобы не дублировать еррор в токен-детерм?
			while (*val->lines[*val->line_index])
				val->lines[*val->line_index]++;
			*str = val->lines[*val->line_index];
			val->dbl_n = 1;
			return (argument);
		}
		token->value = 0;
		val->lines[*val->line_index] += ft_strlen(NAME_CMD_STRING) + 1;
		while (*val->lines[*val->line_index] == ' ' || *val->lines[*val->line_index] == '\t') // скипаем пробелы
			val->lines[*val->line_index]++;
		if (*val->lines[*val->line_index] == '"') // проверяем на открытие ковычек, иначе невалидно
		{
			val->lines[*val->line_index]++; // пропускаем открытую ковычку
			while (val->lines[*val->line_index] && !argument) // пока есть строки
			{
				if (token->value != NULL)
				{
					if (ft_check_closed_quote(val->lines[*val->line_index], val) == 1) // если на одной строке, то стрдап все кроме последнего символа (Ковычек)
						token->value = ft_strjoin(token->value, ft_strndup(val->lines[*val->line_index], ft_strlen(val->lines[*val->line_index])-1)); //проверить утечки
					else
						token->value = ft_strjoin(ft_strjoin(token->value, ft_strndup(val->lines[*val->line_index], ft_strlen(val->lines[*val->line_index]))), "\n"); //проверить утечки
				}
				while (*val->lines[*val->line_index]) // пока есть символы в строке
				{
					if (token->value == NULL) // заполняем value
					{
						if (ft_check_closed_quote(val->lines[*val->line_index], val) == 1) // если на одной строке, то стрдап все кроме последнего символа (Ковычек)
							token->value = ft_strndup(val->lines[*val->line_index], ft_strlen(val->lines[*val->line_index])-1);
						else
							token->value = ft_strndup(ft_strjoin(val->lines[*val->line_index], "\n"), ft_strlen(val->lines[*val->line_index])+1);
					}
					if (*val->lines[*val->line_index] == '"')
					{
						if (ft_strlen(val->lines[*val->line_index]+1)>0) // проверить конец строки??
						{
							val->lines[*val->line_index]++; // пропускаем закрывающую ковычку?
							while (*val->lines[*val->line_index])
								val->lines[*val->line_index]++;
							*str = val->lines[*val->line_index];
							return (argument);
						}
						argument = true;
						token->type = NAME;
						val->name = 1;
						val->lines[*val->line_index]++;
						while (*val->lines[*val->line_index])
							val->lines[*val->line_index]++;
						*str = val->lines[*val->line_index];
						return (argument);
					}
					val->lines[*val->line_index]++;
				}
				*val->line_index += 1;
			}
		}
		while (*val->lines[*val->line_index])
			val->lines[*val->line_index]++;
		*str = val->lines[*val->line_index];
	}
	return (argument);
}

bool	is_comment(const char **str, t_token *token, t_validation	*val)
{
	bool		argument;

	argument = false;
	if (ft_strncmp(val->lines[*val->line_index], COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)) == 0 && val->lines[*val->line_index][ft_strlen(COMMENT_CMD_STRING)] == ' ')
	{
		if (val->comment == 1) //проверка на дубль
		{
			warning_add(ERROR, 1, "Double comment."); //создать новый флаг чтобы не дублировать еррор в токен-детерм?
			while (*val->lines[*val->line_index])
				val->lines[*val->line_index]++;
			*str = val->lines[*val->line_index];
			val->dbl_c = 1;
			return (argument);
		}
		token->value = 0;
		val->lines[*val->line_index] += ft_strlen(COMMENT_CMD_STRING) + 1;
		while (*val->lines[*val->line_index] == ' ' || *val->lines[*val->line_index] == '\t') // скипаем пробелы
			val->lines[*val->line_index]++;
		if (*val->lines[*val->line_index] == '"') // проверяем на открытие ковычек, иначе невалидно
		{
			val->lines[*val->line_index]++; // пропускаем открытую ковычку
			while (val->lines[*val->line_index]) // пока есть строки
			{
				if (token->value != NULL)
				{
					if (ft_check_closed_quote(val->lines[*val->line_index], val) == 1) // если на одной строке, то стрдап все кроме последнего символа (Ковычек)
						token->value = ft_strjoin(token->value, ft_strndup(val->lines[*val->line_index], ft_strlen(val->lines[*val->line_index])-1)); //проверить утечки
					else
						token->value = ft_strjoin(ft_strjoin(token->value, ft_strndup(val->lines[*val->line_index], ft_strlen(val->lines[*val->line_index]))), "\n"); //проверить утечки
				}
				while (*val->lines[*val->line_index]) // пока есть символы в строке
				{
					if (token->value == NULL) // заполняем value
					{
						if (ft_check_closed_quote(val->lines[*val->line_index], val) == 1) // если на одной строке, то стрдап все кроме последнего символа (Ковычек)
							token->value = ft_strndup(val->lines[*val->line_index], ft_strlen(val->lines[*val->line_index])-1);
						else
							token->value = ft_strndup(ft_strjoin(val->lines[*val->line_index], "\n"), ft_strlen(val->lines[*val->line_index])+1);
					}
					if (*val->lines[*val->line_index] == '"')
					{
						if (ft_strlen(val->lines[*val->line_index]+1)>0) // проверить конец строки??
						{
							val->lines[*val->line_index]++; // пропускаем закрывающую ковычку?
							while (*val->lines[*val->line_index])
								val->lines[*val->line_index]++;
							*str = val->lines[*val->line_index];
							return (argument);
						}
						argument = true;
						token->type = COMMENT;
						val->comment= 1;
						val->lines[*val->line_index]++;
						while (*val->lines[*val->line_index])
							val->lines[*val->line_index]++;
						*str = val->lines[*val->line_index];
						return (argument);
					}
					val->lines[*val->line_index]++;
				}
				*val->line_index += 1;
			}
		}
		while (*val->lines[*val->line_index])
			val->lines[*val->line_index]++;
		*str = val->lines[*val->line_index];
	}
	return (argument);
}

int 	ft_validation(const char * const *argv)
{
	t_validation	*validation;

	validation = (t_validation*)malloc(sizeof(*validation));
	validation->have_instructions = 0;
	validation->name = 0;
	validation->comment = 0;
	validation->error = 0;
	validation->dbl_c = 0;
	validation->dbl_n = 0;
	assembler(argv + 1, validation);
	if (validation->have_instructions == 0 || validation->name == 0 || validation->comment == 0 || validation->error == 1)
	{
		write(1, "fail\n", 5);
		free(validation);
		return (0);
	}
	else
		write(1, "OK\n", 3);
	free(validation);
	return (1);
}