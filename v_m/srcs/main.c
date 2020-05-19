/* *********************************************`***************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enshertid <enshertid@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 18:58:47 by enshertid         #+#    #+#             */
/*   Updated: 2020/05/05 11:43:13 by enshertid        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		get_weight(int size, char **answer)
{
	int i;
	int ret;
	
	i = 0;
	ret = size;
	while (ret / 10)
	{
		ret /= 10;
		i++;
	}
	i++;
	ret = i;
	*answer = malloc(sizeof(char) * (i + 1));
	*answer[i] = '\0';
	int j = i;
	j--;
	while (i && j < ret)
	{
		(*answer)[j] = (char)((size % 10) + '0');
		i--;
		size /= 10;
		j--;
	}
	return (ret);
}

static void		introduce(t_players *players)
{
	int i;
	int lenght;
	char *weight;
	int num;
	
	write(1,"Introducing contestants...\n", ft_strlen("Introducing contestants...\n"));
	i = 0;
	while (i < players->size)
	{
		write(1, "* Player ", 9);
		num = i + 1 + '0';
		write(1, &num, 1);
		write (1, ", ", 2);
		lenght = get_weight((int)players->arr[i]->ex_size, &weight);
		write (1, "weighing ", 9);
		write(1, weight, lenght);
		write (1, " bytes, \"", 9);
		write(1, players->arr[i]->name, ft_strlen(players->arr[i]->name));
		write (1, "\" (\"", 4);
		write(1, players->arr[i]->comment, ft_strlen(players->arr[i]->comment));
		write(1, "\") !\n", 5);
		i++;
	}
}

int				main(int ac, char **av)
{
	t_vm vm;
	
	init_data(&vm, ac, av);
	introduce(&vm.players);
	cycle_of_game(&vm);
	destroy_data(&vm);
	return (0);
}
