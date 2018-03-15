/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 01:40:10 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/15 17:29:52 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandelbrot.h"

static void			mandel_init(t_mandel *m, t_f *f)
{
	m->fx = 1;
	m->fy = 1;
	if (((double)X_WIN) / ((double)Y_WIN) < 2.7 / 2.4)
		m->fy = ((double)Y_WIN / 240) / ((double)X_WIN / 270);
	else
		m->fx = ((double)X_WIN / 270) / ((double)Y_WIN / 240);
	m->x1 = (-2.1 + 0.75) * m->fx - 0.75;
	m->x2 = (0.6 + 0.75) * m->fx - 0.75;
	m->y1 = -1.2 * m->fy;
	m->y2 = 1.2 * m->fy;
	m->zoom_x = X_WIN / (m->x2 - m->x1);
	m->zoom_y = Y_WIN / (m->y2 - m->y1);
	m->ite_max = f->event.key.ite;
	m->k = 1;
	m->init = 1;
}

static void			zoom_mandel(t_mandel *m, t_f *f)
{
	double				x_zoom;
	double				y_zoom;

	x_zoom = f->event.mouse.x / m->zoom_x + m->x1;
	y_zoom = f->event.mouse.y / m->zoom_y + m->y1;
	m->x1 = x_zoom - f->event.mouse.zoom * m->fx;
	m->x2 = x_zoom + f->event.mouse.zoom * m->fx;
	m->y1 = y_zoom - f->event.mouse.zoom * m->fy;
	m->y2 = y_zoom + f->event.mouse.zoom * m->fy;
	m->zoom_x = X_WIN / (m->x2 - m->x1);
	m->zoom_y = Y_WIN / (m->y2 - m->y1);
	f->event.mouse.flag = 0;
}

static void			mandel_calcul(t_mandel *m, int x)
{
	double				tmp;
	long				i;
	int					y;

	y = -1;
	while (++y < Y_WIN)
	{
		m->c_r = x / m->zoom_x + m->x1;
		m->c_i = y / m->zoom_y + m->y1;
		m->z_r = 0;
		m->z_i = 0;
		i = 0;
		while ((m->z_r * m->z_r + m->z_i * m->z_i < 4 && i < m->ite_max)
				|| i == 0)
		{
			tmp = m->z_r;
			m->z_r = m->z_r * m->z_r - m->z_i * m->z_i + m->c_r;
			m->z_i = 2 * m->z_i * tmp + m->c_i;
			i++;
		}
		if (i != m->ite_max && check_draw(x, y, X_WIN, Y_WIN) == 1)
			m->img.data[y * X_WIN + x] = m->color * (2 * i + 2);
	}
}

void				draw_mandelbrot(t_f *f, int repaint)
{
	static t_mandel		m;
	int					x;

	if (!m.init)
		mandel_init(&m, f);
	if (repaint == NEW)
	{
		init_img(&m.img, &f->mlx);
		x = -1;
		if (f->event.mouse.flag == 1)
			zoom_mandel(&m, f);
		if (f->event.key.flag == 1 || f->event.key.flag == 2)
			mandel_key(&m, f);
		m.color = f->color;
		while (++x < X_WIN)
			mandel_calcul(&m, x);
	}
	if (repaint == REPAINT || repaint == NEW)
		mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, m.img.ptr, 0, 0);
	f->flags.mandel_repaint = 1;
	if (repaint == DESTROY)
	{
		m.init = 0;
		mlx_destroy_image(f->mlx.ptr, m.img.ptr);
	}
}
