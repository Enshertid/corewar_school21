/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_introduce.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 14:16:01 by ediego            #+#    #+#             */
/*   Updated: 2020/05/24 14:16:05 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		get_weight(int size, char **answer)
{
	int			i;
	int			ret;
	int			j;
	
	i = 1;
	ret = size;
	while (ret / 10 && i++)
		ret /= 10;
	ret = i;
	*answer = malloc(sizeof(char) * (i + 1));
	(*answer)[ret] = '\0';
	j = i;
	while (i-- && --j < ret)
	{
		(*answer)[j] = (char)((size % 10) + '0');
		size /= 10;
	}
	return (ret);
}

void			introduce(t_players *players)
{
	int			i;
	int			lenght;
	char		*weight;
	int			num;
	
	write(1,"Introducing contestants...\n", 27);
	i = -1;
	while (++i < players->size)
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
		free(weight);
	}
}
