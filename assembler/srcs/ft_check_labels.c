/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_labels.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 15:21:15 by jgroleo           #+#    #+#             */
/*   Updated: 2020/05/24 12:58:18 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void		ft_add_label_ind(char *line, char *line2, char **labels, int *i)
{
	line = line2;
	line += 1;
	labels[*i] = ft_strdup(line);
	(*i)++;
}

void		ft_add_label_dir(char *line, char *line2, char **labels, int *i)
{
	line = line2;
	line += 2;
	labels[*i] = ft_strdup(line);
	(*i)++;
}

void		ft_collect_labels(t_vector_token *t, char **labels, int *i,
		t_validation *val)
{
	int		row;
	int		col;
	char	*line;

	line = NULL;
	row = 0;
	while (row < vec_size(&t))
	{
		col = 0;
		if (t[row][col].type != 6)
			ft_check_string(t, row, val);
		while (col < vec_size(&t[row]))
		{
			if (t[row][col].type == 2 && t[row][col].value[0] == ':')
				ft_add_label_ind(line, t[row][col].value, labels, i);
			if (t[row][col].type == 2 && t[row][col].value[1] == ':')
				ft_add_label_dir(line, t[row][col].value, labels, i);
			col++;
		}
		row++;
	}
}

void		ft_check_labels(t_vector_token *tokens, t_validation *val)
{
	int		row;
	char	**labels;
	int		i;
	int		flag;

	i = 0;
	labels = (char**)malloc(vec_size(&tokens) * sizeof(char*));
	ft_collect_labels(tokens, labels, &i, val);
	while (--i > -1)
	{
		flag = 0;
		row = 0;
		while (row < vec_size(&tokens) && flag == 0)
		{
			if (tokens[row][0].type == 0 && ft_strcmp(labels[i],
					tokens[row][0].value) == 0)
				flag = 1;
			row++;
		}
		if (flag == 0)
			ft_nonexist_l(val, labels, i);
		free(labels[i]);
	}
	free(labels);
}

void		ft_parse_args(t_vector_token *t, int r, int *c, t_validation *val)
{
	int	prev;

	(*c)++;
	prev = 2;
	while (*c < vec_size(&t[r]))
	{
		if (prev == 2 && t[r][*c].type == 3)
		{
			prev = 3;
			(*c)++;
		}
		else if (prev == 3 && t[r][*c].type == 2)
		{
			prev = 2;
			(*c)++;
		}
		else
		{
			val->error = 1;
			warning_add(ERROR, 3, "wrong tokens order in line №",
						ft_itoa_static(r + val->extr + 1, 10), ".");
			break ;
		}
	}
}
