/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 23:58:55 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/10 04:38:19 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"

static void			*pre_draw_map(void *arg)
{
	int				tx;
	int				ty;

	t_data		*data;
	data = (t_data *)arg;
	tx = (data->block_id % data->f->t.nb_block_x) * X_CHUNK;
	ty = (data->block_id / data->f->t.nb_block_y) * Y_CHUNK;
	draw_map(data->f, tx, ty);
	return (NULL);
}

static void			thread_struct_init(t_f *f)
{
	f->t.nb_block_x = X_WIN / X_CHUNK + (X_WIN % X_CHUNK != 0 ? 1 : 0);
	f->t.nb_block_y = Y_WIN / Y_CHUNK + (Y_WIN % Y_CHUNK != 0 ? 1 : 0);
}

static int			new_thread(int *block_id, t_f *f, pthread_t t[NB_THREAD])
{
	static int		count = 0;
	t_data			*data;

	while (count < NB_THREAD && *block_id < NB_BLOCK_P)
	{
		data = (t_data *)ft_memalloc(sizeof(t_data));
		count++;
		data->block_id = *block_id;
		data->f = f;
		pthread_create(&t[count], NULL, pre_draw_map, data);
		(*block_id)++;
	}
	return (count);
}

void				thread_init(t_f *f)
{
	int				block_id;
	int				count; //nb de thread
	int				count_2; //compteur pour allez juste qu'au nb de thread
	pthread_t		thread[NB_THREAD];

	block_id = 0;
	count = 0;
	count_2 = 0;
	thread_struct_init(f);
	while (block_id < NB_BLOCK)
	{
		count = new_thread(&block_id, f, thread);
		while (count_2 < count)
		{
			count_2++;
			pthread_join(thread[count_2], NULL);
		}
	}
}
