/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 15:21:15 by jgroleo           #+#    #+#             */
/*   Updated: 2020/06/03 20:31:59 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

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

void	ft_scroll_line(char **str, char **lines, int line_index)
{
	if (line_index < vec_size(&lines))
	{
		if (lines[line_index] != NULL)
		{
			while (*lines[line_index] != '\0')
				lines[line_index]++;
			*str = lines[line_index];
		}
	}
}

void	ft_parse_string(t_vector_token *t, int row, int *col, t_validation *val)
{
	int		a;

	if (t[row][*col].type != 1 && t[row][*col].type != 6)
		ft_synt_error(val, row);
	else
	{
		a = *col;
		if (vec_size(&t[row]) - 1 >= a + 1)
		{
			(*col)++;
			if (t[row][*col].value)
			{
				if (t[row][*col].type != 2 && t[row][0].type != 4 &&
				t[row][0].type != 5)
					ft_synt_error(val, row);
				else
					ft_parse_args(t, row, col, val);
			}
		}
	}
}

void	ft_check_string(t_vector_token *tokens, int row, t_validation *val)
{
	int	col;

	if (tokens[row][0].type != 7)
	{
		if (vec_size(&tokens[row]) > 7)
			ft_synt_error(val, row);
		else
		{
			col = 0;
			if (tokens[row][0].type == 0 || tokens[row][0].type == 4
				|| tokens[row][0].type == 5)
				col++;
			if (col < vec_size(&tokens[row]))
				ft_parse_string(tokens, row, &col, val);
		}
	}
}
