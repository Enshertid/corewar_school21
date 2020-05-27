#ifndef FILE_H
# define FILE_H

#include "token.h"

enum	e_file_status
{
	FILE_OK,
	FILE_EMPTY,
	FILE_NO_FINAL_NEWLINE
};

typedef enum e_file_status	t_file_status;

typedef struct		s_file
{
	const char 		*name;
	int				fd;
	t_vector_char	*lines;
	t_vector_char	*copy;
	t_vector_char	*bytecode;
	t_vector_token	*tokens;
	t_file_status	status;
}					t_file;

#endif
