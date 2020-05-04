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
	UNKNOWN
};

typedef struct			s_token
{
	enum e_token_types	type;
	char				*value;

}						t_token;

typedef	t_token*	t_vector_token;

t_vector_token	*tokenizer(t_vector_char *lines, t_validation	*validation);
t_token			token_create(const char *str, size_t *symbols_skip);

#endif
