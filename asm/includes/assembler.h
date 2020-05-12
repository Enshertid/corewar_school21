#ifndef ASSEMBLER_H
# define ASSEMBLER_H

 #include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
//  #include "op.h"
// #include "token.h"
#include "file.h"
#include "valid.h"

void		assembler(const char * const *files, t_validation	*validation);
void		assembly(t_file *file, t_validation	*validation);
void		ft_check_labels(t_vector_token *tokens, t_validation *val);
void		ft_check_instructions(t_vector_token *tokens, t_validation *val);
void 		ft_check_sizes(t_vector_token *tokens, t_validation *val);
void		ft_check_arg(t_check_args *checker, t_validation *val, int row);
void		write_to_file(const t_file *file,
						const t_vector_char *bytecode);

#endif
