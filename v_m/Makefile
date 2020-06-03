# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ediego <ediego@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/26 12:26:50 by ediego            #+#    #+#              #
#    Updated: 2020/05/26 12:28:59 by ediego           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

SRCS =	main.c	pars.c pars_argv.c	pars_champ.c	op_with_args.c			\
game.c	carets_op_delete.c	op_functions.c	data_init.c	vm_init.c			\
carets_op.c	output.c	data_destroy.c	game_checks.c	game_end.c			\
op_with_dif_args.c		op_with_args2.c	pars_dump.c	out_introduce.c			\
op_reg_work.c		pars_valid_champ_name.c									\
op/op_live.c	op/op_ld.c		op/op_st.c	op/op_add.c		op/op_ldi.c		\
op/op_sub.c		op/op_and.c		op/op_or.c	op/op_xor.c		op/op_zjmp.c	\
op/op_sti.c		op/op_fork.c	op/op_lld.c	op/op_lldi.c	op/op_lfork.c	\
op/op_aff.c\

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
	@mkdir -p $(OBJ_DIR)/op

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
