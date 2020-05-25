/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 23:08:06 by user              #+#    #+#             */
/*   Updated: 2020/05/12 23:09:11 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LABEL_H
# define LABEL_H

# include <stdint.h>

typedef struct	s_label
{
	const char	*name;
	uint32_t	bytes_before;
}				t_label;

typedef t_label*	t_vector_label;

#endif
