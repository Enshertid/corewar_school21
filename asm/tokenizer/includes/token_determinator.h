/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_determinator.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 12:56:46 by user              #+#    #+#             */
/*   Updated: 2020/04/25 13:46:32 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_DETERMINATOR_H
# define TOKEN_DETERMINATOR_H

# include "token.h"

t_token	token_determinator(const char **lineptr, t_validation	*validation);

bool	is_label(const char **lineptr, t_token *token);
bool	is_argument(const char **lineptr, t_token *token);
bool	is_separator(const char **lineptr, t_token *token);
bool	is_instruction(const char **lineptr, t_token *token, t_validation *validation);
bool	is_name(const char **str, t_token *token, t_validation *validation);
bool	is_comment(const char **str, t_token *token, t_validation *val);
bool	is_empty(const char **str, t_token *token);

#endif
