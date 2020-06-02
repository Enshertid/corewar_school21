/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_determinator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enshertid <enshertid@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 12:57:45 by user              #+#    #+#             */
/*   Updated: 2020/06/03 01:12:36 by enshertid        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/token_determinator.h"
#include "assembler.h"

static void	skip_unknown_token(const char **lineptr)
{
	const char *line = *lineptr;

	while (*line && *line != ' ' && *line != '\t')
		line += 1;
	*lineptr = line;
}

void		ft_mark_error_token(const char **s, t_token *t, t_validation *v)
{
	t->type = UNKNOWN;
	if (t->value != NULL && ft_strlen(t->value) > 0)
		free(t->value);
	t->value = NULL;
	v->error = 1;
	if (v->dbl_c == 0 && v->dbl_n == 0)
	{
		if (*v->line_index >= (int)v->lines_count)
			warning_add(ERROR, 3, "syntax error in line №",
					ft_itoa_static(*v->line_index, 10), ".");
		else
			warning_add(ERROR, 3, "syntax error in line №",
					ft_itoa_static(*v->line_index + 1, 10), ".");
	}
	ft_scroll_line((char**)s, v->lines, *v->line_index);
}

t_token		token_determinator(const char **lineptr, t_validation *validation)
{
	t_token	token;
	bool	token_determined;

	token.value = NULL;
	token_determined = false;
	token_determined = is_separator(lineptr, &token);
	if (!token_determined)
		token_determined = is_label(lineptr, &token);
	if (!token_determined)
		token_determined = is_instruction(lineptr, &token, validation);
	if (!token_determined)
		token_determined = is_argument(lineptr, &token);
	if (!token_determined)
		token_determined = is_name(lineptr, &token, validation);
	if (!token_determined)
		token_determined = is_comment(lineptr, &token, validation);
	if (!token_determined)
	{
		ft_mark_error_token(lineptr, &token, validation);
		skip_unknown_token(lineptr);
	}
	return (token);
}
