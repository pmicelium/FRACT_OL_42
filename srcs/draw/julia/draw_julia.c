/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:41:01 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/02 02:03:23 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "julia.h"

static int		set_color(t_julia j, int i)
{
	int		color;
	int		r;
	int		g;
	int		b;

	color = 0;
	r = 0;
	g = i * 255 / j.ite_max;
	b = 0;
	color = (r & 0xFF) << 16 | (g & 0xFF) << 8 | (b & 0xFF);
	return (color);
}

static t_julia	init_julia(t_julia j)
{
	j.fx = 1;
	j.fy = 1;
	if (((double)X_WIN) / ((double)Y_WIN) < 200 / 2.4)
		j.fy = ((double)Y_WIN / 240) / ((double)X_WIN / 200);
	else
		j.fx = ((double)X_WIN / 200) / ((double)Y_WIN / 240);
	j.x1 = -1 * j.fx;
	j.x2 = 1 * j.fx;
	j.y1 = -1.2 * j.fy;
	j.y2 = 1.2 * j.fy;
	j.c_r = 0.285;
	j.c_i = 0.01;
	j.zoom_x = X_WIN / (j.x2 - j.x1);
	j.zoom_y = Y_WIN / (j.y2 - j.y1);
	j.ite_max = 50.0;
	j.k = 1;
	j.init = 1;
	j.init2 = 0;
	return (j);
}

static void		zoom_julia(t_julia *j, t_f *f)
{
	double				x_zoom;
	double				y_zoom;
	static double		zoom = 1;

	x_zoom = f->event.mouse.x / j->zoom_x + j->x1;
	y_zoom = f->event.mouse.y / j->zoom_y + j->y1;
	j->x1 = x_zoom - f->event.mouse.zoom * j->fx;
	j->x2 = x_zoom + f->event.mouse.zoom * j->fx;
	j->y1 = y_zoom - f->event.mouse.zoom * j->fy;
	j->y2 = y_zoom + f->event.mouse.zoom * j->fy;
	j->zoom_x = X_WIN / (j->x2 - j->x1);
	j->zoom_y = Y_WIN / (j->y2 - j->y1);
	if (f->event.mouse.zoom >= zoom)
		j->ite_max -= f->event.key.nb_ite;
	else
		j->ite_max += f->event.key.nb_ite;
	zoom = f->event.mouse.zoom;
	f->event.mouse.flag = 0;
	j->init2 = 1;
}

static void		change_c(t_julia *j, t_f *f)
{
	j->c_r = ((f->event.motion.x * ((double)X_WIN / j->zoom_x)) / X_WIN) * 2;
	j->c_i = ((f->event.motion.y * ((double)Y_WIN / j->zoom_y)) / Y_WIN) * 2;
//a changer
}

void			draw_julia(t_f *f, int repaint)
{
	static t_julia		j;
	int					x;
	int					y;
	int					i;
	double				tmp;

	if (!j.init)
	{
		j = init_julia(j);
		f->event.mouse.zoom /= 0.25;
	}
	if (repaint == NEW)
	{
		j.img.ptr = mlx_new_image(f->mlx.ptr, X_WIN, Y_WIN);
		j.img.data = (int*)mlx_get_data_addr(j.img.ptr, &j.img.bpp,
				&j.img.lsize, &j.img.endian);
		x = 0;
		if (f->event.motion.flag == 1)
			change_c(&j, f);
		if (f->event.mouse.flag == 1 || j.init2 == 0)
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
