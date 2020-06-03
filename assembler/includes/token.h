/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 22:39:22 by user              #+#    #+#             */
/*   Updated: 2020/06/02 21:59:37 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "libft.h"
# include "op.h"
# include "valid.h"

enum	e_token_types
{
	LABEL,
	INSTRUCTION,
	ARGUMENT,
	SEPARATOR,
	NAME,
	COMMENT,
	UNKNOWN,
	EMPTY
};

typedef struct			s_token
{
	enum e_token_types	type;
	char				*value;

}						t_token;

typedef	t_token*		t_vector_token;

t_vector_token			*tokenizer(t_vector_char *lines,
									t_validation *validation);

#endif
