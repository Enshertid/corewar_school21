#include "assembler.h"

#include <stdio.h> // DELETE

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

//void	ft_check_instructions(t_vector_char *lines, t_vector_token *tokens, t_validation	*val)
//{
//
//}

void	ft_check_labels(t_vector_token *tokens, t_validation	*val)
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
//		printf("LLine %d: %s\n", row, lines[row]);
//		printf("TTokens:\n");
		col = 0;
		while (col < vec_size(&tokens[row]))
		{
//			printf("\tTType: %s, value: \"%s\"\n", types[tokens[row][col].type],
//				   tokens[row][col].value);
			if (tokens[row][col].type == 2 && tokens[row][col].value[0] == ':')
			{
				line = tokens[row][col].value;
				line += 1;
				labels[i] = ft_strdup(line);
//				printf("arg_label[%d]:%s\n", i, labels[i]);
				i++;
			}
			if (tokens[row][col].type == 2 && tokens[row][col].value[1] == ':')
			{
				line = tokens[row][col].value;
				line += 2;
				labels[i] = ft_strdup(line);
//				printf("arg_label[%d]:%s\n", i, labels[i]);
				i++;
			}
			col++;
		}
//		printf("\n");
		row++;
	}

	int 	flag;
	while (--i > -1)
	{
		flag = 0;
//		printf("arg_label[%d]:%s\n", i, labels[i]);
		row = 0;
		while (row < vec_size(&tokens))
		{
			if (tokens[row][0].type == 0 && ft_strcmp(labels[i], tokens[row][0].value) == 0)
			{
//				printf("label[%d]:%s\n", row, tokens[row][0].value);
				flag = 1;
			}
			row++;
		}
		if (flag == 0)
		{
			printf("ERROR, WRONG LABEL\n");
			val->error = 1;
		}
		free(labels[i]);
//		printf("\n");
	}
	free(labels);
}

bool	is_name(const char **str, t_token *token, t_validation	*val)
{
	bool		argument;
//	const char	*line = *str;

	argument = false;
	if (val->name == 1) //проверка на дубль
		return (argument);
	token->value = 0;
	if (ft_strncmp(val->lines[*val->line_index], NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) == 0 && val->lines[*val->line_index][ft_strlen(NAME_CMD_STRING)] == ' ')
	{
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
						token->value = ft_strjoin(token->value, ft_strndup(val->lines[*val->line_index], ft_strlen(val->lines[*val->line_index]))); //проверить утечки
				}
//				printf("#строки:%d str:%s\n", *val->line_index, val->lines[*val->line_index]);
				while (*val->lines[*val->line_index]) // пока есть символы в строке
				{
					if (token->value == NULL) // заполняем value
					{
						if (ft_check_closed_quote(val->lines[*val->line_index], val) == 1) // если на одной строке, то стрдап все кроме последнего символа (Ковычек)
							token->value = ft_strndup(val->lines[*val->line_index], ft_strlen(val->lines[*val->line_index])-1);
						else
							token->value = ft_strndup(val->lines[*val->line_index], ft_strlen(val->lines[*val->line_index]));
					}
//					printf("c:|%c|\n", *val->lines[*val->line_index]);
					if (*val->lines[*val->line_index] == '"')
					{
						if (ft_strlen(val->lines[*val->line_index]+1)>0) // проверить конец строки??
						{
//							printf("something after \":|%s|\n", val->lines[*val->line_index ]+ 1);
//							printf("#строки:%d str:%s\n", *val->line_index, val->lines[*val->line_index]);
							val->lines[*val->line_index]++; // пропускаем закрывающую ковычку?
//							printf("#строки:%d str:%s\n", *val->line_index, val->lines[*val->line_index]);
							while (*val->lines[*val->line_index])
							{
//								printf("str:%s\n", line);
								val->lines[*val->line_index]++;
							}
							*str = val->lines[*val->line_index];
							return (argument);
						}
//						printf("bingo, str:%s\n", line);
						argument = true;
						token->type = NAME;
//						token->value = ft_strndup(*str, ft_strlen(NAME_CMD_STRING));
						val->name = 1;
						val->lines[*val->line_index]++;
						while (*val->lines[*val->line_index])
						{
//							printf("str:%s\n", line);
							val->lines[*val->line_index]++;
						}
						*str = val->lines[*val->line_index];
						return (argument);
					}
					val->lines[*val->line_index]++;
				}
				*val->line_index += 1;
//				printf("i2:%d\n", *val->line_index);
			}
		}
	}
	while (*val->lines[*val->line_index])
	{
//		printf("str:%s\n", line);
		val->lines[*val->line_index]++;
	}
	*str = val->lines[*val->line_index];
	return (argument);
}

bool	is_comment(const char **str, t_token *token, t_validation	*val)
{
	bool		argument;
//	const char	*line = *str;

	argument = false;
	if (val->comment == 1) //проверка на дубль
		return (argument);
	token->value = 0;
	if (ft_strncmp(val->lines[*val->line_index], COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)) == 0 && val->lines[*val->line_index][ft_strlen(COMMENT_CMD_STRING)] == ' ')
	{
		val->lines[*val->line_index] += ft_strlen(COMMENT_CMD_STRING) + 1;
//		printf("1:|%s|, #строки:|%d|\n", val->lines[*val->line_index], *val->line_index);
		while (*val->lines[*val->line_index] == ' ' || *val->lines[*val->line_index] == '\t') // скипаем пробелы
			val->lines[*val->line_index]++;
//		printf("2:|%s|, #строки:|%d|\n", val->lines[*val->line_index], *val->line_index);
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
						token->value = ft_strjoin(token->value, ft_strndup(val->lines[*val->line_index], ft_strlen(val->lines[*val->line_index]))); //проверить утечки
				}
//				printf("#строки:%d str:%s\n", *val->line_index, val->lines[*val->line_index]);
				while (*val->lines[*val->line_index]) // пока есть символы в строке
				{
					if (token->value == NULL) // заполняем value
					{
						if (ft_check_closed_quote(val->lines[*val->line_index], val) == 1) // если на одной строке, то стрдап все кроме последнего символа (Ковычек)
							token->value = ft_strndup(val->lines[*val->line_index], ft_strlen(val->lines[*val->line_index])-1);
						else
							token->value = ft_strndup(val->lines[*val->line_index], ft_strlen(val->lines[*val->line_index]));
					}
//					printf("c:|%c|\n", *val->lines[*val->line_index]);
					if (*val->lines[*val->line_index] == '"')
					{
						if (ft_strlen(val->lines[*val->line_index]+1)>0) // проверить конец строки??
						{
//							printf("something after \":|%s|\n", val->lines[*val->line_index ]+ 1);
//							printf("#строки:%d str:%s\n", *val->line_index, val->lines[*val->line_index]);
							val->lines[*val->line_index]++; // пропускаем закрывающую ковычку?
//							printf("#строки:%d str:%s\n", *val->line_index, val->lines[*val->line_index]);
							while (*val->lines[*val->line_index])
							{
//								printf("str:%s\n", line);
								val->lines[*val->line_index]++;
							}
							*str = val->lines[*val->line_index];
							return (argument);
						}
//						printf("bingo, str:%s\n", line);
						argument = true;
						token->type = COMMENT;
//						token->value = ft_strndup(*str, ft_strlen(COMMENT_CMD_STRING));
						val->comment= 1;
						val->lines[*val->line_index]++;
						while (*val->lines[*val->line_index])
						{
//							printf("str:%s\n", line);
							val->lines[*val->line_index]++;
						}
						*str = val->lines[*val->line_index];
						return (argument);
					}
					val->lines[*val->line_index]++;
				}
				*val->line_index += 1;
//				printf("#строки:%d\n", *val->line_index);
			}
		}
	}
	while (*val->lines[*val->line_index])
	{
//		printf("str:%s\n", line);
		val->lines[*val->line_index]++;
	}
	*str = val->lines[*val->line_index];
	return (argument);
}

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

int 	ft_validation(const char * const *argv)
{
	t_validation	*validation;

	validation = (t_validation*)malloc(sizeof(*validation));
	validation->have_instructions = 0;
	validation->name = 0;
	validation->comment = 0;
	validation->error = 0;
	assembler(argv + 1, validation);
	if (validation->have_instructions == 0 || validation->name == 0 || validation->comment == 0 || validation->error == 1)
	{
		write(1, "fail\n", 5);
		free(validation);
		return (0);
	}
	free(validation);
	return (1);
}
