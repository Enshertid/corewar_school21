/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enshertid <enshertid@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 15:21:15 by jgroleo           #+#    #+#             */
/*   Updated: 2020/06/03 01:17:53 by enshertid        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int			ft_dbl_n(char **str, t_validation *v)
{
	if (v->name == 1)
	{
		warning_add(ERROR, 3, "Extra name in line №",
					ft_itoa_static(*v->line_index + v->extr + 1, 10), ".");
		ft_scroll_line(str, v->lines, *v->line_index);
		v->dbl_n = 1;
		return (1);
	}
	return (0);
}

static void	add(t_dstr *name, const char *close_quote, t_validation *v)
{
	if (!*name)
		*name = dstr_create_from_srcn(v->lines[*v->line_index],
		close_quote ? (size_t)(close_quote - v->lines[*v->line_index]) :
		ft_strlen(v->lines[*v->line_index]));
	else
		dstr_add_strn(name, v->lines[*v->line_index], close_quote ?
					(size_t)(close_quote - v->lines[*v->line_index]) :
					ft_strlen(v->lines[*v->line_index]));
}

bool		parse_name(t_validation *v, t_token *token, char **str)
{
	t_dstr		name;
	const char	*close_quote = NULL;
	bool		done;

	name = NULL;
	done = false;
	while (*v->line_index < vec_size(&v->lines) && !close_quote)
	{
		close_quote = ft_strchr(v->lines[*v->line_index], '\"');
		add(&name, close_quote, v);
		if (!close_quote)
		{
			*v->line_index += 1;
			dstr_add_chr(&name, '\n');
		}
		else
		{
			done = true;
			token->type = NAME;
			token->value = dstr_to_str(name);
			v->comment = 1;
			*str = (char*)close_quote + 1;
		}
	}
	return (done);
}

bool		is_name(const char **str, t_token *token, t_validation *v)
{
	if (ft_strnequ(NAME_CMD_STRING, *str, ft_strlen(NAME_CMD_STRING)))
	{
		if (ft_dbl_c((char**)str, v) == 1)
			return (false);
		v->lines[*v->line_index] = *(char**)str + ft_strlen(NAME_CMD_STRING);
		while (*v->lines[*v->line_index] == ' ' ||
		*v->lines[*v->line_index] == '\t')
			v->lines[*v->line_index]++;
		if (*v->lines[*v->line_index] == '"')
		{
			v->lines[*v->line_index]++;
			return (parse_name(v, token, (char**)str));
		}
		else
			return (false);
	}
	else
		return (false);
}
