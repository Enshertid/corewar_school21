NAME =				a.out


SRCS =				main.c			\
					assembler.c		\
					assembly.c		\
					validation.c	\
					converter/add_args.c	\
					converter/add_command.c	\
					converter/add_to_labels_list.c	\
					converter/byte_tokenizer.c		\
					converter/convert_to_byte_tokens.c	\
					converter/converter.c				\
					converter/fill_labels.c						\
					tokenizer/is_argument.c				\
					tokenizer/is_instruction.c			\
					tokenizer/is_label.c				\
					tokenizer/is_separator.c			\
					tokenizer/token_determinator.c				\
					tokenizer/tokenizer.c





LIBFT =				$(addprefix $(DIR_LIBFT)/, libft.a)

DIR_LIBFT =			../libft
DIR_SRCS =			srcs
DIR_OBJS =			./objs

OBJS =				$(addprefix $(DIR_OBJS)/, $(SRCS:.c=.o))

INCLUDES =			includes				\
					$(DIR_LIBFT)/includes	\
					includes/converter		\
					includes/tokenizer

FLAGS =				-g -Wall -Werror -Wextra $(addprefix -I , $(INCLUDES))



all: $(NAME)


$(NAME): $(DIR_OBJS) $(OBJS)
	make -C $(DIR_LIBFT)
	gcc $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)


$(DIR_OBJS):
	@mkdir -p $(DIR_OBJS)
	@mkdir -p $(DIR_OBJS)/converter
	@mkdir -p $(DIR_OBJS)/tokenizer


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
