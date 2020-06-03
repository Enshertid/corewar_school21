/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_tokenizer_utils.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 22:39:44 by user              #+#    #+#             */
/*   Updated: 2020/05/25 22:46:32 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BYTE_TOKENIZER_UTILS_H
# define BYTE_TOKENIZER_UTILS_H

# include "token.h"
# include "byte_token.h"
# include "byteline.h"
# include "label.h"

t_vector_byteline	byte_tokenizer(t_vector_token *tokens);
void				add_command(t_byteline *byteline,
								t_vector_token tokens, int pos);
void				add_args(t_byteline *byteline,
							t_vector_token tokens, int pos);
void				fill_jumps(t_vector_byteline bytelines,
								t_vector_label labels);
t_vector_label		get_labels_list(t_vector_token *tokens,
									t_vector_byteline bytelines);

#endif
