/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_champ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:23:37 by ediego            #+#    #+#             */
/*   Updated: 2020/05/26 12:23:39 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"

static void			check_m_h(t_pars *pars)
{
	char			buf[5];
	int				m_h;

	if ((read(pars->fd, &buf, 4)) < 4)
		ft_error("magic header is wrong", "check_m_h", 2);
	buf[4] = '\0';
	*((char*)&m_h) = buf[3];
	*((char*)&m_h + 1) = buf[2];
	*((char*)&m_h + 2) = buf[1];
	*((char*)&m_h + 3) = buf[0];
	if (m_h != COREWAR_EXEC_MAGIC)
		ft_error("magic header is wrong", "check_m_h", 2);
}

static void			valid_exc_size(t_pars *pars, t_players *players)
{
	char			buf[5];
	int				exc_size;

	if ((read(pars->fd, buf, 4)) != 4)
		ft_error("ex_code size is wrong", "valid_exc_size", 2);
	buf[4] = '\0';
	*((char*)&exc_size) = buf[3];
	*((char*)&exc_size + 1) = buf[2];
	*((char*)&exc_size + 2) = buf[1];
	*((char*)&exc_size + 3) = buf[0];
	if (exc_size > CHAMP_MAX_SIZE)
		ft_error("ex code is too large", "valid_ex_size", 2);
	players->arr[players->iter]->ex_size = exc_size;
}

static void			check_comment(t_pars *pars, t_players *players)
{
	char			buf[COMMENT_LENGTH + 1];
	char			*comment;
	int32_t			ln;

	if ((read(pars->fd, buf, COMMENT_LENGTH)) != COMMENT_LENGTH)
		ft_error("wrong size of champion's name", "valid_champ_name", 2);
	buf[COMMENT_LENGTH] = '\0';
	ln = ft_strlen(buf);
	comment = ft_calloc(ln + 1, sizeof(char));
	comment[ln] = '\0';
	ft_memcpy(comment, buf, ln);
	players->arr[players->iter]->comment = comment;
	if ((read(pars->fd, buf, 4)) != 4)
		ft_error("NULL oktet's are invalid", "valid_champ_name", 2);
}

static void			valid_ex_code(t_pars *pars, t_players *players)
{
	char			buf[players->arr[players->iter]->ex_size];
	char			*ex_code;

	if ((read(pars->fd, buf, players->arr[players->iter]->ex_size)) !=
		(ssize_t)players->arr[players->iter]->ex_size)
		ft_error("wrong size of champion's name", "valid_champ_name", 2);
	ex_code = ft_calloc(players->arr[players->iter]->ex_size, sizeof(char));
	ft_memcpy(ex_code, buf, players->arr[players->iter]->ex_size);
	players->arr[players->iter]->ex_code = ex_code;
}

void				pars_champ(t_pars *pars, t_players *players)
{
	check_m_h(pars);
	valid_champ_name(pars, players);
	valid_exc_size(pars, players);
	check_comment(pars, players);
	valid_ex_code(pars, players);
	players->iter++;
	pars->i++;
}
