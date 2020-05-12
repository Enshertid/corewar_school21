#ifndef BYTE_TOKENIZER_UTILS_H
#define BYTE_TOKENIZER_UTILS_H

# include "token.h"
# include "byte_token.h"
# include "byteline.h"

t_vector_byteline	byte_tokenizer(const t_vector_token *tokens);
void				add_command(t_byteline *byteline,
								const t_vector_token tokens, int pos);
void				add_args(t_byteline *byteline,
							const t_vector_token tokens, int pos);
 void				fill_labels(t_vector_byteline bytelines);

#endif














/*

create [fractol_name/number;window_size;threads]

close[fractol_name/number]

exit // close all

*/
