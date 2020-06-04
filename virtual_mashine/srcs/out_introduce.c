/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_introduce.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:22:50 by ediego            #+#    #+#             */
/*   Updated: 2020/05/26 12:22:50 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		get_weight(int size, char **answer)
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
}

void			introduce(t_players *players)
{
	int			i;
	char		*weight;
	int			num;

	write(1, "Introducing contestants...\n", 27);
	i = -1;
	while (++i < players->size)
	{
		write(1, "* Player ", 9);
		num = i + 1 + '0';
		write(1, &num, 1);
		write(1, ", ", 2);
		get_weight((int)players->arr[i]->ex_size, &weight);
		write(1, "weighing ", 9);
		write(1, weight, ft_strlen(weight));
		write(1, " bytes, \"", 9);
		write(1, players->arr[i]->name, ft_strlen(players->arr[i]->name));
		write(1, "\" (\"", 4);
		write(1, players->arr[i]->comment, ft_strlen(players->arr[i]->comment));
		write(1, "\") !\n", 5);
		free(weight);
	}
}
