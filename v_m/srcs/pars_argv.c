/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego  <ediego@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 18:44:19 by enshertid         #+#    #+#             */
/*   Updated: 2020/04/15 22:11:17 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdio.h>
#include "op.h"

static t_bool		is_dir(const char *filename)
{
	struct stat		statbuf;

	if (stat(filename, &statbuf) == 0)
	{
		if (S_ISDIR(statbuf.st_mode))
		{
			warning_add(ERROR, 3, "\"", filename, "\" is directory");
			return (TRUE);
		}
	}
	return (FALSE);
}

static void			sort_id(t_players *players, size_t i, size_t j)
{
	t_player		*tmp;
	t_player		**ar;

	ar = ft_calloc(MAX_PLAYERS, sizeof(t_player*));
	while (++i < players->iter)
		if (!players->arr[i]->flag_of_n)
			ar[j++] = players->arr[i];
	i = -1;
	while (++i < players->iter)
		while (players->arr[i]->flag_of_n && i != players->arr[i]->id - 1)
		{
			tmp = players->arr[players->arr[i]->id - 1];;
			players->arr[players->arr[i]->id - 1] = players->arr[i];
			players->arr[i] = tmp;
		}
	i = -1;
	j = 0;
	while (++i < players->iter)
	{
		if (!players->arr[i]->flag_of_n)
			players->arr[i] = ar[j++];
		players->arr[i]->id = i + 1;
	}
	i = -1;
	while (++i < players->iter)
	{
		// printf("\nname==>%s\nid==>%zu\ncomment==>%s\nex_code==>%s\n",
		// players->arr[i]->name,players->arr[i]->id, players->arr[i]->comment, players->arr[i]->ex_code);
	}
	free(ar);
}

void				validate_id(t_players *players)
{
	size_t			i;
	size_t			j;

	i = -1;
	while (++i < players->iter)
	{
		if (players->arr[i]->id > players->iter)
			ft_error ("too large id", "validate_id", 2);
		j = i;
		while (++j < players->iter)
			if (players->arr[i]->flag_of_n && players->arr[j]->
			flag_of_n && players->arr[i]->id == players->arr[j]->id)
				ft_error("id can't repeat", "validate_id", 2);
	}
	i = -1;
	j = 0;
	sort_id(players, i, j);
}

void				valid_name(t_pars *pars, t_players *players)
{
	char			*ptr;

	if (pars->i == pars->ac)
		ft_error("have no champ after flag", "valid_name", 2);
	ptr = pars->av[pars->i] + (ft_strlen(pars->av[pars->i]) - 4);
	if (!ft_strequ(ptr, ".cor"))
		ft_error("invalid format of file", "valid_name", 2);
	if ((pars->fd = open(pars->av[pars->i], O_RDONLY)) < 1)
		ft_error("invalid file", "valid_name", 2);
	is_dir(pars->av[pars->i]);
	if (players->iter >= MAX_PLAYERS)
		ft_error("too many champions", "pars_champ", 2);
	if (!players->arr[players->iter])
		players->arr[players->iter] = ft_calloc(1, sizeof(t_player));
	players->arr[players->iter]->id = players->iter + 1;
	players->arr[players->iter]->flag_of_n = FALSE;
}

void				valid_flag(t_pars *pars, t_players *players)
{
	size_t			iter;
	int				id;

	iter = 0;
	pars->i++;
	while (pars->av[pars->i][iter])
	{
		if (!ft_isdigit(pars->av[pars->i][iter]))
			ft_error("id is incorrect", "pars_id", 2);
		iter++;
	}
	id = ft_atoi(pars->av[pars->i++]);
	if ((id > MAX_PLAYERS) || (id < 1))
		ft_error ("id is incorrect", "pars id", 2);
	valid_name(pars, players);
	players->arr[players->iter - 1]->flag_of_n = TRUE;
	players->arr[players->iter - 1]->id = id;
}