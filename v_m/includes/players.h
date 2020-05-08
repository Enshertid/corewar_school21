 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enshertid <enshertid@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 19:27:56 by enshertid         #+#    #+#             */
/*   Updated: 2020/04/03 14:31:26 by enshertid        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYERS_H
# define PLAYERS_H

#include "libft.h"

typedef struct			s_player
{
	char				*name;
	char				*comment;
	char				*ex_code;
	int					id;
	t_bool				flag_of_n;
	size_t				ex_size;
	size_t 				live;
}						t_player;

typedef struct			s_players
{
	t_player		**arr;
	int				size;
	int				iter;
}						t_players;

#endif
