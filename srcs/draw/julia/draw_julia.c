/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:41:01 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/10 04:35:57 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fract.h"

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

static t_julia	init_julia(t_julia j, t_f *f)
{
	j.fx = 1;
	j.fy = 1;
	if (((double)X_WIN) / ((double)Y_WIN) < 200 / 240)
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
	j.k = 1;
	j.init = 1;
	j.init2 = 0;
	j.ite_max = f->event.key.ite;
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
	j->init2 = 1;
}

static void		change_c(t_julia *j, t_f *f)
{
	j->c_r = (((f->event.motion.x * (j->x2 - j->x1)) / ((double)X_WIN))) - (j->x2 - j->x1) / 2.0;
	j->c_i = (((f->event.motion.y * (j->y2 - j->y1)) / ((double)Y_WIN))) - (j->y2 - j->y1) / 2.0;
}

static void		julia_key(t_julia *j, t_f *f)
{
	if (f->event.key.ite > 0)
		j->ite_max = f->event.key.ite;
}

void			draw_julia(t_f *f, int tx, int ty)
{
	int					x;
	int					y;
	unsigned long		i;
	double				tmp;

	x = 0;
	while (x < X_WIN)
	{
		y = 0;
		while (y < Y_WIN)
		{
			f->j.z_r = x / f->j.zoom_x + f->j.x1;
			f->j.z_i = y / f->j.zoom_y + f->j.y1;
			i = 0;
			while ((f->j.z_r * f->j.z_r + f->j.z_i * f->j.z_i <= 4 && i < f->j.ite_max)
					|| i == 0)
			{
				tmp = f->j.z_r;
				f->j.z_r = (f->j.z_r * f->j.z_r) - (f->j.z_i * f->j.z_i) + f->j.c_r;
				f->j.z_i = 2 * f->j.z_i * tmp + f->j.c_i;
				i++;
			}
			if (i != f->j.ite_max && check_draw(x, y, X_WIN, Y_WIN) == 1)
				f->img.data[y * X_WIN + x] = set_color(f->j, i);
			y++;
		}
		x++;
	}
}
