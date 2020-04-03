# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enshertid <enshertid@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/02 18:51:40 by enshertid         #+#    #+#              #
#    Updated: 2020/04/03 19:48:40 by enshertid        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Corewar

SRCS =	main.c	parsing.c	players.c	ft_memalloc.c	\
pars_id.c		pars_champ.c							\

SRCS_DIR =			./srcs/

OBJ_DIR =			./obj/

LIB_DIR=			../libft/

OBJ =				$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

HEAD_LIB =			../libft/includes/

HEAD_COR =			./includes/

FLAGS =			-g -Wall -Werror -Wextra $(addprefix -I , $(HEAD_LIB)) $(addprefix -I , $(HEAD_COR))


all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@make -C $(LIB_DIR) -s
	@gcc $(FLAGS) $(OBJ) $(LIB_DIR)libft.a -o $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)


$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	@gcc $(FLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ_DIR)
	@make c -C $(LIB_DIR) -s

fclean: clean
	@rm -f $(NAME)
	@make f -C $(LIB_DIR) -s

re: fclean all

c: clean

f: fclean

.PHONY: al*l clean fclean c f debug
