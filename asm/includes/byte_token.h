/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_token.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 13:18:10 by user              #+#    #+#             */
/*   Updated: 2020/05/10 16:53:52 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BYTE_TOKEN_H
# define BYTE_TOKEN_H

# include <stdint.h>
# include "token.h"

typedef struct			s_byte_token
{
	const t_token		*token;
	int32_t				value;
	int					value_size;
}						t_byte_token;

typedef t_byte_token*	t_vector_bytetoken;

#endif
