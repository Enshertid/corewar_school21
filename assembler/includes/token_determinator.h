/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_determinator.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enshertid <enshertid@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 12:56:46 by user              #+#    #+#             */
/*   Updated: 2020/06/03 01:35:23 by enshertid        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_DETERMINATOR_H
# define TOKEN_DETERMINATOR_H

# include "token.h"

t_token	token_determinator(const char **lineptr, t_validation	*validation);

bool	is_label(const char **lineptr, t_token *token);
bool	is_argument(const char **lineptr, t_token *token);
bool	is_separator(const char **lineptr, t_token *token);
bool	is_instruction(const char **lineptr, t_token *token,
					t_validation *validation);
bool	is_empty(const char **str, t_token *token);

#endif
