/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_champ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enshertid <enshertid@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 19:31:10 by enshertid         #+#    #+#             */
/*   Updated: 2020/04/05 16:57:56 by enshertid        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "op.h"
#include "stdio.h"

static void			check_m_h(t_pars *pars)
{
	char			buf[5];
	size_t			ret;
	int				m_h = 0;

	if ((ret = read(pars->fd, &buf, 4)) < 4)
		ft_error("magic header is wrong", "check_m_h", 2);
	buf[4] = '\0';
	*((char*)&m_h) = buf[3];
	*((char*)&m_h + 1) = buf[2];
	*((char*)&m_h + 2) = buf[1];
	*((char*)&m_h + 3) = buf[0];
	if (m_h != COREWAR_EXEC_MAGIC)
		ft_error("magic header is wrong", "check_m_h", 2);
}

static void			valid_champ_name(t_pars *pars, t_players *players)
{
	char			buf[PROG_NAME_LENGTH + 1];
	char			*name;
	size_t			ret;

	if ((ret = read(pars->fd, buf, PROG_NAME_LENGTH)) != PROG_NAME_LENGTH)
		ft_error ("wrong size of champion's name", "valid_champ_name", 2);
	buf[PROG_NAME_LENGTH] = '\0';
	size_t size = ft_strlen(buf);
	name = ft_calloc(size + 1, sizeof(char));
	name[size] = '\0';
	ft_memcpy(name, buf, size);
	players->arr[players->iter]->name = name;
	if ((ret = read(pars->fd, buf, 4)) != 4)
		ft_error("NULL oktet's are invalid", "valid_champ_name", 2);
}

static void			valid_exc_size(t_pars *pars, t_players *players)
{
	char			buf[5];
	size_t			ret;
	int			exc_size;

	if ((ret = read(pars->fd, buf, 4)) != 4)
		ft_error ("ex_code size is wrong", "valid_exc_size", 2);
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
	size_t			ret;

	if ((ret = read(pars->fd, buf, COMMENT_LENGTH)) != COMMENT_LENGTH)
		ft_error ("wrong size of champion's name", "valid_champ_name", 2);
	buf[COMMENT_LENGTH] = '\0';
	comment = ft_calloc(ft_strlen(buf), sizeof(char));
	comment[ft_strlen(buf) - 1] = '\0';
	ft_memcpy(comment, buf, ft_strlen(buf));
	players->arr[players->iter]->comment = comment;
	if ((ret = read(pars->fd, buf, 4)) != 4)
		ft_error("NULL oktet's are invalid", "valid_champ_name", 2);
}

static void			valid_ex_code(t_pars *pars, t_players *players)
{
	char			buf[players->arr[players->iter]->ex_size + 1];
	char			*ex_code;
	size_t			ret;

	if ((ret = read(pars->fd, buf, players->arr[players->iter]->ex_size)) != players->arr[players->iter]->ex_size)
		ft_error ("wrong size of champion's name", "valid_champ_name", 2);
	buf[players->arr[players->iter]->ex_size] = '\0';
	ex_code = ft_calloc(ft_strlen(buf), sizeof(char));
	ex_code[ft_strlen(buf) - 1] = '\0';
	ft_memcpy(ex_code, buf, ft_strlen(buf));
	players->arr[players->iter]->ex_code = ex_code;
}

void				pars_champ(t_pars *pars, t_players *players)
{
	check_m_h(pars);
	valid_champ_name(pars, players);
	valid_exc_size(pars, players);
	check_comment(pars, players);
	valid_ex_code(pars,players);
	players->iter++;
	pars->i++;
}
