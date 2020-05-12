/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byteline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 17:35:15 by user              #+#    #+#             */
/*   Updated: 2020/05/10 17:37:37 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BYTELINE_H
# define BYTELINE_H

# include "byte_token.h"

typedef struct			s_byteline
{
	t_vector_bytetoken	bytetokens;
	int32_t			bytes_before;
	t_vector_char		*labels;
}						t_byteline;

typedef t_byteline*		t_vector_byteline;

#endif
