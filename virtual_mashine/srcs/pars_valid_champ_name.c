/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_valid_champ_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:24:12 by ediego            #+#    #+#             */
/*   Updated: 2020/05/26 12:24:13 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"

void				valid_champ_name(t_pars *pars, t_players *players)
{
	char			buf[PROG_NAME_LENGTH + 1];
	char			*name;
	size_t			size;

	if ((read(pars->fd, buf, PROG_NAME_LENGTH)) != PROG_NAME_LENGTH)
		ft_error("wrong size of champion's name", "valid_champ_name", 2);
	buf[PROG_NAME_LENGTH] = '\0';
	size = ft_strlen(buf);
	name = ft_calloc(size + 1, sizeof(char));
	name[size] = '\0';
	ft_memcpy(name, buf, size);
	players->arr[players->iter]->name = name;
	if ((read(pars->fd, buf, 4)) != 4)
		ft_error("NULL oktet's are invalid", "valid_champ_name", 2);
}
