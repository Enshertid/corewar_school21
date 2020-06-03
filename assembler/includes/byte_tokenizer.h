/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_tokenizer.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 13:20:56 by user              #+#    #+#             */
/*   Updated: 2020/05/08 13:20:56 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BYTE_TOKENIZER_H
# define BYTE_TOKENIZER_H

# include "token.h"
# include "byteline.h"

t_vector_byteline	byte_tokenizer(t_vector_token *tokens);

#endif
