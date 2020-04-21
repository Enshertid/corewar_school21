/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enshertid <enshertid@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 18:44:23 by enshertid         #+#    #+#             */
/*   Updated: 2020/04/05 13:01:43 by enshertid        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

#include "libft.h"
#include "op.h"
#include "parsing.h"
#include "players.h"

typedef struct			s_data
{
	t_pars				pars;
	t_players			players;
}						t_data;

void					parsing(t_pars *pars, t_players *players);

#endif
