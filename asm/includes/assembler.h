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

void				assembler(const char * const *files, t_validation	*validation);
void				assembly(t_file *file, t_validation	*validation);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_check_aff(t_check_args *checker, t_validation *val, int row);
void				ft_check_zjmp_l_f_lf(t_check_args *checker, t_validation *val, int row);
void				ft_check_st(t_check_args *checker, t_validation *val, int row);
void				ft_check_add_sub(t_check_args *checker, t_validation *val, int row);
void				ft_check_and_or_xor(t_check_args *checker, t_validation *val, int row);
void				ft_check_ldi_lldi(t_check_args *checker, t_validation *val, int row);
void				ft_check_sti(t_check_args *checker, t_validation *val, int row);
bool				useless_line(const char *line);
int					ft_check_closed_quote(char *str, t_validation *val);
t_check_args		*ft_malloc_checker(int *row, int *i);
void				ft_check_one_arg(t_check_args *checker, t_validation *val, int row);
void				ft_check_two_arg(t_check_args *checker, t_validation *val, int row);
void				ft_check_three_arg(t_check_args *checker, t_validation *val, int row);
void				ft_check_arg(t_check_args *checker, t_validation *val, int row);
int					ft_check_last_arg(t_vector_token *t, int row, int col);
void				ft_last_t_not_arg(t_validation *val, int i);
void				ft_parse_i(t_vector_token *t, int row, int *col, t_check_args *checker);
void				ft_inc_i_row(int *i, int *row);
void				ft_check_instructions(t_vector_token *tokens, t_validation *val);
void				ft_synt_error(t_validation *val, int row);
void				ft_large_n(t_validation *val);
void				ft_large_c(t_validation *val);
void				ft_check_sizes(t_vector_token *tokens, t_validation *val);
void				ft_nonexist_l(t_validation *val, char **labels, int i);
void				ft_scroll_line(const char **str, char **lines, int line_index);
void				ft_parse_string(t_vector_token *t, int row, int *col, t_validation *val);
void				ft_check_string(t_vector_token *tokens, int row, t_validation *val);
bool				is_empty(const char **str, t_token *token);
void				ft_add_label_ind(char *line, char *line2, char **labels, int *i);
void				ft_add_label_dir(char *line, char *line2, char **labels, int *i);
void				ft_collect_labels(t_vector_token *t, char **labels, int *i,
		t_validation *val);
void				ft_check_labels(t_vector_token *tokens, t_validation *val);
void				ft_parse_args(t_vector_token *t, int row, int *col, t_validation *val);
int					ft_check_n_string(t_validation *v);
int					ft_fill_name(const char **str, t_validation *v, t_token *t, bool *a);
int					ft_dbl_n(const char **str, t_validation *v);
int					ft_parse_name(const char **str, t_validation *v, t_token *t, bool *a);
bool				is_name(const char **str, t_token *token, t_validation *v);
int					ft_check_com_string(t_validation *v);
int					ft_fill_com(const char **str, t_validation *v, t_token *t, bool *a);
int					ft_dbl_c(const char **str, t_validation *v);
int					ft_parse_com(const char **str, t_validation *v, t_token *t, bool *a);
bool				is_comment(const char **str, t_token *token, t_validation *v);
void				ft_keep_fill_value(t_token *token, t_validation *v);
void				mark_name(const char **str, t_validation *v, t_token *t, bool *a);
void				mark_c(const char **str, t_validation *v, t_token *t, bool *a);
void				ft_fill_value(t_token *token, t_validation *v);
t_validation		*ft_create_val(void);

#endif
