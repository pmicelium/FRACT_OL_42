/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:41:01 by pmiceli           #+#    #+#             */
/*   Updated: 2018/02/28 18:37:51 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "julia.h"

static int			set_color(t_julia j, int i)
{
	int		color;
	int		r;
	int		g;
	int		b;

	color = 0;
	r = 0;
	g = 0;
	b = i * 255 / j.ite_max;
	color = (r & 0xFF) << 16 | (g & 0xFF) << 8 | (b & 0xFF);
	return (color);
}

static t_julia	init_julia(t_julia j)
{
	j.x1 = 2.1;
	j.x2 = -2.1;
	j.y1 = -1.2;
	j.y2 = 1.2;
	j.c_r = 0.285;
	j.c_i = 0.01;
	j.zoom_x = X_WIN / (j.x2 - j.x1);
	j.zoom_y = Y_WIN / (j.y2 - j.y1);
	j.ite_max = 50.0;
	j.k = 1;
	j.init = 1;
	return (j);
}

static void		zoom_julia(t_julia *j, t_f *f)
{
	double				x_zoom;
	double				y_zoom;
	static double		zoom = 0.78;

	x_zoom = f->event.mouse.x / j->zoom_x + j->x1;
	y_zoom = f->event.mouse.y / j->zoom_y + j->y1;
	j->x1 = x_zoom - f->event.mouse.zoom;
	j->x2 = x_zoom + f->event.mouse.zoom;
	j->y1 = y_zoom - f->event.mouse.zoom;
	j->y2 = y_zoom + f->event.mouse.zoom;
	j->zoom_x = X_WIN / (j->x2 - j->x1);
	j->zoom_y = Y_WIN / (j->y2 - j->y1);
	if (f->event.mouse.zoom >= zoom)
		j->ite_max -= f->event.key.nb_ite;
	else
		j->ite_max += f->event.key.nb_ite;
	f->event.mouse.flag = 0;
}

void			draw_julia(t_f *f, int repaint)
{
	static t_julia		j;
	int					x;
	int					y;
	int					i;
	double				tmp;

	if (!j.init)
		j = init_julia(j);
	if (repaint == NEW)
	{
		j.img.ptr = mlx_new_image(f->mlx.ptr, X_WIN, Y_WIN);
		j.img.data = (int*)mlx_get_data_addr(j.img.ptr, &j.img.bpp,
				&j.img.lsize, &j.img.endian);
		x = 0;
		if (f->event.mouse.flag == 1)
			zoom_julia(&j, f);
		while (x < X_WIN)
		{
			y = 0;
			while (y < Y_WIN)
			{
				j.z_r = x / j.zoom_x + j.x1;
				j.z_i = y / j.zoom_y + j.y1;
				i = 0;
				while ((j.z_r * j.z_r + j.z_i * j.z_i <= 4 && i < j.ite_max)
				|| i == 0)
				{
					tmp = j.z_r;
					j.z_r = (j.z_r * j.z_r) - (j.z_i * j.z_i) + j.c_r;
					j.z_i = 2 * j.z_i * tmp + j.c_i;
					i++;
				}
				if (i != j.ite_max && check_draw(x, y, X_WIN, Y_WIN) == 1)
					j.img.data[y * X_WIN + x] = set_color(j, i);
				y++;
			}
			x++;
		}
	}
	if (repaint == REPAINT || repaint == NEW)
		mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, j.img.ptr, 0, 0);
	f->flags.julia_repaint = 1;
	if (repaint == DESTROY)
	{
		j.init = 0;
		mlx_destroy_image(f->mlx.ptr, j.img.ptr);
	}
}
