/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 20:56:18 by user              #+#    #+#             */
/*   Updated: 2020/06/03 20:56:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYERS_H
# define PLAYERS_H

# include "libft.h"

typedef struct			s_player
{
	char				*name;
	char				*comment;
	char				*ex_code;
	int					id;
	bool				flag_of_n;
	size_t				ex_size;
}						t_player;

typedef struct			s_players
{
	t_player			**arr;
	int8_t				size;
	int8_t				iter;
	int8_t				dump_size;
	int32_t				dump_num;
	bool				aff;
}						t_players;

#endif
