/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 01:40:10 by pmiceli           #+#    #+#             */
/*   Updated: 2018/02/28 22:39:58 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandelbrot.h"

static int			set_color(t_mandel m, int i)
{
	int		color;
	int		r;
	int		g;
	int		b;

	color = 0;
	r = i * 255 / m.ite_max;
	g = 0;
	b = 0;
	color = (r & 0xFF) << 16 | (g & 0xFF) << 8 | (b & 0xFF);
	return (color);
}

static t_mandel		mandel_init(t_mandel m)
{
	double		fx;
	double		fy;

	fx = 1;
	fy = 1;
	if (((double)X_WIN) / ((double)Y_WIN) < 2.7 / 2.4)
		fy = ((double)Y_WIN / 240) / ((double)X_WIN / 270);
	else
		fx = ((double)X_WIN / 270) / ((double)Y_WIN / 240);
	m.x1 = (-2.1 + 0.75) * fx - 0.75;
	m.x2 = (0.6 + 0.75) * fx - 0.75;
	m.y1 = -1.2 * fy;
	m.y2 = 1.2 * fy;
	m.zoom_x = X_WIN / (m.x2 - m.x1);
	m.zoom_y = Y_WIN / (m.y2 - m.y1);
	m.ite_max = 50.0;
	m.k = 1;
	m.init = 1;
	return (m);
}

static void			zoom_mandel(t_mandel *m, t_f *f)
{
	double				x_zoom;
	double				y_zoom;
	static double		zoom = 0.78;

	x_zoom = f->event.mouse.x / m->zoom_x + m->x1;
	y_zoom = f->event.mouse.y / m->zoom_y + m->y1;
	m->x1 = x_zoom - f->event.mouse.zoom;
	m->x2 = x_zoom + f->event.mouse.zoom;
	m->y1 = y_zoom - f->event.mouse.zoom;
	m->y2 = y_zoom + f->event.mouse.zoom;
	m->zoom_x = X_WIN / (m->x2 - m->x1);
	m->zoom_y = Y_WIN / (m->y2 - m->y1);
	if (f->event.mouse.zoom >= zoom)
		m->ite_max -= f->event.key.nb_ite;
	else
		m->ite_max += f->event.key.nb_ite;
	f->event.mouse.flag = 0;
}

void				draw_mandelbrot(t_f *f, int repaint)
{
	static t_mandel		m;
	int					x;
	int					y;
	int					i;
	double				tmp;

	if (!m.init)
		m = mandel_init(m);
	if (repaint == NEW)
	{
		m.img.ptr = mlx_new_image(f->mlx.ptr, X_WIN, Y_WIN);
		m.img.data = (int*)mlx_get_data_addr(m.img.ptr, &m.img.bpp,
				&m.img.lsize, &m.img.endian);
		x = 0;
		if (f->event.mouse.flag == 1)
			zoom_mandel(&m, f);
		while (x < X_WIN)
		{
			y = 0;
			while (y < Y_WIN)
			{
				m.c_r = x / m.zoom_x + m.x1;
				m.c_i = y / m.zoom_y + m.y1;
				m.z_r = 0;
				m.z_i = 0;
				i = 0;
				while ((m.z_r * m.z_r + m.z_i * m.z_i < 4 && i < m.ite_max)
						|| i == 0)
				{
					tmp = m.z_r;
					m.z_r = m.z_r * m.z_r - m.z_i * m.z_i + m.c_r;
					m.z_i = 2 * m.z_i * tmp + m.c_i;
					i++;
				}
				if (i != m.ite_max && check_draw(x, y, X_WIN, Y_WIN) == 1)
					m.img.data[y * X_WIN + x] = set_color(m, i);
				y++;
			}
			x++;
		}
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
