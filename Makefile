# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enshertid <enshertid@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/03 01:36:05 by enshertid         #+#    #+#              #
#    Updated: 2020/06/03 01:37:23 by enshertid        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	make -C ./asm
	make -C ./v_m

clean:
	make clean -C ./asm
	make clean -C ./v_m

fclean: clean
	make fclean -C ./asm
	make fclean -C ./v_m

re: fclean all
