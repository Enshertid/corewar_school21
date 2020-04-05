/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enshertid <enshertid@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 19:16:10 by enshertid         #+#    #+#             */
/*   Updated: 2020/04/04 14:55:08 by enshertid        ###   ########.fr       */
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
	char				**av;
	int					ac;
	int					fd;
	int					i;
}						t_pars;

void					validate_id(t_players *players);
void					valid_flag(t_pars *pars, t_players *players);
void					valid_name(t_pars *pars, t_players *players);

void					pars_champ(t_pars *pars, t_players *players);

#endif
