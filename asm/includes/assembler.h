#ifndef ASSEMBLER_H
# define ASSEMBLER_H

 #include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
//  #include "op.h"
// #include "token.h"
#include "file.h"

void		assembler(char **files);
void		assembly(t_file *file);

#endif
