/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 00:51:45 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/15 00:21:49 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int						loop_hook(t_f *f)
{
	static int		i = 0;

	mlx_clear_window(f->mlx.ptr, f->mlx.win);
	draw_map(f, f->fract);
	if (f->help.flag == 1)
	{
		if (i < 120)
			i += 10;
		mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, f->help.img.ptr,
			0, Y_WIN - i);
	}
	else
	{
		if (i > 0)
			i -= 10;
		if (i != 0)
			mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, f->help.img.ptr,
			0, Y_WIN - i);
	}
	fps(f);
	return (0);
}
