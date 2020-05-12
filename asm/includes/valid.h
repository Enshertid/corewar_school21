#ifndef VALID_H
# define VALID_H

typedef struct			s_validation
{
	int					have_instructions;
	int 				name;
	int 				comment;
	char 				**lines;
	int 				*line_index;
	int					error;
	int 				dbl_n;
	int 				dbl_c;
}						t_validation;

typedef struct			s_check_args
{
	int					i;
	char 				*instr;
	char 				**arg;
}						t_check_args;

int 					ft_validation(const char * const *argv);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
void					ft_name_validation(const char **str, t_validation	*validation);

#endif
