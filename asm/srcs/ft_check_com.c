/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_com.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 15:21:15 by jgroleo           #+#    #+#             */
/*   Updated: 2020/06/03 20:39:41 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int			ft_dbl_c(char **str, t_validation *v)
{
	if (v->comment == 1)
	{
		warning_add(ERROR, 3, "Extra comment in line №",
					ft_itoa_static(*v->line_index + v->extr + 1, 10), ".");
		ft_scroll_line(str, v->lines, *v->line_index);
		v->dbl_c = 1;
		return (1);
	}
	return (0);
}

static void	add(t_dstr *comment, const char *close_quote, t_validation *v)
{
	if (!*comment)
		*comment = dstr_create_from_srcn(v->lines[*v->line_index],
		close_quote ? (size_t)(close_quote - v->lines[*v->line_index]) :
		ft_strlen(v->lines[*v->line_index]));
	else
		dstr_add_strn(comment, v->lines[*v->line_index], close_quote ?
					(size_t)(close_quote - v->lines[*v->line_index]) :
					ft_strlen(v->lines[*v->line_index]));
}

bool		prepare(t_token *token, t_dstr comment, t_validation *v)
{
	token->type = COMMENT;
	token->value = dstr_to_str(comment);
	v->name = 1;
	return (true);
}

bool		parse_comment(t_validation *v, t_token *token, char **str)
{
	t_dstr		comment;
	const char	*close_quote = NULL;
	bool		done;

	comment = NULL;
	done = false;
	while (*v->line_index < vec_size(&v->lines) && !close_quote)
	{
		close_quote = ft_strchr(v->lines[*v->line_index], '\"');
		add(&comment, close_quote, v);
		if (!close_quote)
		{
			*v->line_index += 1;
			dstr_add_chr(&comment, '\n');
		}
		else
		{
			done = prepare(token, comment, v);
			*str = (char*)close_quote + 1;
		}
	}
	if (!done)
		dstr_destroy(comment);
	return (done);
}

bool		is_comment(const char **str, t_token *token, t_validation *v)
{
	if (ft_strnequ(COMMENT_CMD_STRING, *str, ft_strlen(COMMENT_CMD_STRING)))
	{
		if (ft_dbl_n((char**)str, v) == 1)
			return (false);
		v->lines[*v->line_index] = *(char**)str + ft_strlen(COMMENT_CMD_STRING);
		while (*v->lines[*v->line_index] == ' ' ||
		*v->lines[*v->line_index] == '\t')
			v->lines[*v->line_index]++;
		if (*v->lines[*v->line_index] == '"')
		{
			v->lines[*v->line_index]++;
			return (parse_comment(v, token, (char**)str));
		}
		else
			return (false);
	}
	else
		return (false);
}
