NAME =				a.out


SRCS =				main.c			\
					assembler.c		\
					assembly.c		\
					tokenizer.c





LIBFT =				$(addprefix $(DIR_LIBFT)/, libft.a)

DIR_LIBFT =			../libft
DIR_SRCS =			srcs
DIR_OBJS =			./objs

OBJS =				$(addprefix $(DIR_OBJS)/, $(SRCS:.c=.o))

INCLUDES =			includes				\
					$(DIR_LIBFT)/includes

FLAGS =				-g -Wall -Werror -Wextra $(addprefix -I , $(INCLUDES))



# all: $(NAME)

all:
	gcc -g -Wall -Werror -Wextra srcs/*.c srcs/tokenizer/*.c 	\
	-I includes -I includes/tokenizer -I ../libft/includes	\
	-L ../libft -lft


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
