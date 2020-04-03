/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enshertid <enshertid@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 19:16:10 by enshertid         #+#    #+#             */
/*   Updated: 2020/04/03 20:10:49 by enshertid        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "players.h"
#include "libft.h"

typedef struct			s_pars
{
	int					ac;
	int					fd;
	char				**av;
	char				**line;
}						t_pars;

void					validate_id(t_players *players);
void					pars_champ(t_pars *pars, t_players *players, int *i);

#endif
