NAME =				asm


SRCS =				add_args.c							\
					add_command.c						\
					assembler.c							\
					assembly.c							\
					byte_tokenizer.c					\
					converter.c							\
					fill_jumps.c						\
					finders.c							\
					generate_bytecode.c					\
					is_argument.c						\
					is_instruction.c					\
					is_label.c							\
					is_separator.c						\
					main.c								\
					token_determinator.c				\
					tokenizer.c							\
					write_to_file.c						\
					free_file.c							\
					ft_fills.c							\
					ft_check_dup_inst.c					\
					ft_check_args.c						\
					ft_check_com.c						\
					ft_check_instrs_three.c				\
					ft_check_instrs_two.c				\
					ft_check_instrs.c					\
					ft_check_labels.c					\
					ft_check_name.c						\
					ft_check_sizes.c					\
					ft_marks.c							\
					ft_strs.c 							\
					ft_validation.c						\


LIBFT =				$(addprefix $(DIR_LIBFT)/, libft.a)

DIR_LIBFT =			../libft
DIR_SRCS =			srcs
DIR_OBJS =			./objs

OBJS =				$(addprefix $(DIR_OBJS)/, $(SRCS:.c=.o))

INCLUDES =			includes				\
					$(DIR_LIBFT)/includes	\


FLAGS =				-g -Wall -Werror -Wextra $(addprefix -I , $(INCLUDES))



all: $(NAME)


$(NAME): $(DIR_OBJS) $(OBJS)
	make -C $(DIR_LIBFT)
	gcc $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)


$(DIR_OBJS):
	@mkdir -p $(DIR_OBJS)


$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	gcc $(FLAGS) -o $@ -c $<


clean:
	@rm -rf $(DIR_OBJS)


fclean: clean
	@rm -f $(NAME)


re: fclean all


c: clean


f: fclean


.PHONY: all clean fclean c f debug
