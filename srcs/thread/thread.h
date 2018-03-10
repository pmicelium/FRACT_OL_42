/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 00:19:30 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/10 01:03:36 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H
# include "../../includes/fract.h"

# define NB_BLOCK (t.nb_block_x * t.nb_block_y)
# define NB_BLOCK_P (t->nb_block_x * t->nb_block_y)

typedef struct		s_thread
{
	int				nb_block_x;
	int				nb_block_y;
}					t_thread;

typedef struct		s_data
{
	int				block_id;
	s_f				*f;
}					t_data;

#endif
