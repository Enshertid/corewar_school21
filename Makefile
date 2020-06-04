# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enshertid <enshertid@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/03 01:36:05 by enshertid         #+#    #+#              #
#    Updated: 2020/06/04 15:10:10 by enshertid        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM_NAME =	asm
VM_NAME =	corewar

ASM_DIR =	assembler
VM_DIR =	virtual_mashine

all:
	make -C libft
	make -C $(ASM_DIR)
	make -C $(VM_DIR)
	mv $(ASM_DIR)/$(ASM_NAME) .
	mv $(VM_DIR)/$(VM_NAME) .

clean:
	make clean -C libft
	make clean -C $(ASM_DIR)
	make clean -C $(VM_DIR)

fclean: clean
	make fclean -C libft
	make fclean -C $(ASM_DIR)
	make fclean -C $(VM_DIR)
	rm -rf $(ASM_NAME)
	rm -rf $(VM_NAME)

re: fclean all
