/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ship.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 19:26:42 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/15 18:12:30 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ship.h"

static void		ship_init(t_ship *s, t_f *f)
{
	s->fx = 1;
	s->fy = 1;
	if (((double)X_WIN) / ((double)Y_WIN) < 2.7 / 2.4)
		s->fy = ((double)Y_WIN / 240) / ((double)X_WIN / 270);
	else
		s->fx = ((double)X_WIN / 270) / ((double)Y_WIN / 240);
	s->x1 = (-2.1 + 0.75) * s->fx - 0.75;
	s->x2 = (0.6 + 0.75) * s->fx - 0.75;
	s->y1 = -1.2 * s->fy;
	s->y2 = 1.2 * s->fy;
	s->zoom_x = X_WIN / (s->x2 - s->x1);
	s->zoom_y = Y_WIN / (s->y2 - s->y1);
	s->ite_max = 50.0;
	s->k = 1;
	s->init = 1;
	s->init2 = 1;
	f->event.mouse.zoom /= 0.5;
}

static void			zoom_ship(t_ship *s, t_f *f)
{
	double				x_zoom;
	double				y_zoom;
	static double		zoom = 1;

	x_zoom = f->event.mouse.x / s->zoom_x + s->x1;
	y_zoom = f->event.mouse.y / s->zoom_y + s->y1;
	s->x1 = x_zoom - f->event.mouse.zoom * s->fx;
	s->x2 = x_zoom + f->event.mouse.zoom * s->fx;
	s->y1 = y_zoom - f->event.mouse.zoom * s->fy;
	s->y2 = y_zoom + f->event.mouse.zoom * s->fy;
	s->zoom_x = X_WIN / (s->x2 - s->x1);
	s->zoom_y = Y_WIN / (s->y2 - s->y1);
	zoom = f->event.mouse.zoom;
	f->event.mouse.flag = 0;
	s->init2 = 0;
}

void				ship_calcul(t_ship *s, int x, int color)
{
	int					y;
	int					i;
	double				tmp;

	y = 0;
	while (y < Y_WIN)
	{
		s->c_r = x / s->zoom_x + s->x1;
		s->c_i = y / s->zoom_y + s->y1;
		s->z_r = 0;
		s->z_i = 0;
		i = 0;
		while ((s->z_r * s->z_r + s->z_i * s->z_i < 4 && i < s->ite_max)
				|| i == 0)
		{
			tmp = s->z_r;
			s->z_r = s->z_r * s->z_r - s->z_i * s->z_i + s->c_r;
			s->z_i = 2 * fabs(s->z_i * tmp) + s->c_i;
			i++;
		}
		if (i != s->ite_max && check_draw(x, y, X_WIN, Y_WIN) == 1)
			s->img.data[y * X_WIN + x] = color * (2 * i + 2);
		y++;
	}
	x++;
}

void				draw_ship(t_f *f, int repaint)
{
	static t_ship		s;
	int					x;

	if (!s.init)
		ship_init(&s, f);
	if (repaint == NEW)
	{
		init_img(&s.img, &f->mlx);
		x = -1;
		if (f->event.mouse.flag == 1 || s.init2 == 1)
			zoom_ship(&s, f);
		if (f->event.key.flag == 1 || f->event.key.flag == 2)
			ship_key(&s, f);
		while (++x < X_WIN)
			ship_calcul(&s, x, f->color);
	}
	if (repaint == REPAINT || repaint == NEW)
		mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, s.img.ptr, 0, 0);
	f->flags.ship_repaint = 1;
	if (repaint == DESTROY)
	{
		s.init = 0;
		mlx_destroy_image(f->mlx.ptr, s.img.ptr);
	}
}
