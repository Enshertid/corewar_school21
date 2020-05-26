/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:26:03 by ediego            #+#    #+#             */
/*   Updated: 2020/05/26 12:26:05 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARS_H
# define PARS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "players.h"
# include "libft.h"
# include "op.h"

# define DUMP 2

typedef struct			s_pars
{
	char				**av;
	int					ac;
	int					fd;
	int					i;
	bool				dump_flag;
}						t_pars;

void					validate_id(t_players *players);
bool					valid_dump(t_pars *pars, t_players *players);
void					valid_flag(t_pars *pars, t_players *players);
void					valid_name(t_pars *pars, t_players *players);

void					pars_champ(t_pars *pars, t_players *players);
void					parsing(t_players *players, int ac, char **av);
void					valid_champ_name(t_pars *pars, t_players *players);

int64_t					ft_atotoi(const char *str);

#endif