NAME =				reader

SRCS =				main.c		\
					print.c		\
					print_hex.c

DIR_OBJS =			./objs

OBJS =				$(addprefix $(DIR_OBJS)/, $(SRCS:.c=.o))


INCLUDES =			../libft/includes

FLAGS =			-g -Wall -Werror -Wextra $(addprefix -I , $(INCLUDES))



all: $(NAME)

$(NAME): $(DIR_OBJS) $(OBJS)
	@make -C ../libft -s
	@gcc $(FLAGS) $(OBJS) ../libft/libft.a -o $(NAME)

$(DIR_OBJS):
	@mkdir -p $(DIR_OBJS)


$(DIR_OBJS)/%.o: %.c
	@gcc $(FLAGS) -o $@ -c $<

clean:
	@rm -rf $(DIR_OBJS)
	@make c -C ../libft -s

fclean: clean
	@rm -f $(NAME)
	@make f -C ../libft -s

re: fclean all

c: clean

f: fclean

.PHONY: all clean fclean c f debug
