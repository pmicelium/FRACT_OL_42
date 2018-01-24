/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 00:34:59 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/24 03:18:36 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fps.h"

static void		print_fps(t_f *f, char *tmp_2)
{
	int		i;
	int		j;

	j = 0;
	while (j < 18)
	{
		i = 0;
		while (i < 26)
		{
			mlx_pixel_put(f->mlx.ptr, f->mlx.win, X_WIN - 43 + i, 28 + j,
					BLACK);
			i++;
		}
		j++;
	}
	mlx_string_put(f->mlx.ptr, f->mlx.win, X_WIN - 40, 25, GREEN, tmp_2);
}

void			fps(t_f *f)
{
	static t_fps					fps;
	static struct timespec			last;
	static unsigned int				tmp;
	char							*tmp_2;
	struct timespec					tmptime;

	fps.fps++;
	if (!last.tv_nsec)
		clock_gettime(CLOCK_MONOTONIC_RAW, &last);
	clock_gettime(CLOCK_MONOTONIC_RAW, &tmptime);
	fps.start += (tmptime.tv_sec - last.tv_sec) * 1000000000 +
		(tmptime.tv_nsec - last.tv_nsec);
	clock_gettime(CLOCK_MONOTONIC_RAW, &last);
	if (((float)fps.start / 1000000000) >= 0.25)
	{
		tmp = fps.start / fps.fps;
		fps.fps = 0;
		fps.start = 0;
	}
	tmp_2 = tmp == 0 ? ft_strdup("0") : ft_itoa((int)((float)1 /
				((float)tmp / 1000000000)));
	print_fps(f, tmp_2);
	free(tmp_2);
}
