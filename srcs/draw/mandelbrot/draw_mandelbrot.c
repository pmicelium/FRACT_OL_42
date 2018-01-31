/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 01:40:10 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/31 02:34:17 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandelbrot.h"

static int		set_color(t_mandel m, int i)
{
	int			color;
	int			r;
	int			g;
	int			b;

	color = 0;
	r = i * 255 / m.ite_max;
	g = 0;
	b = 0;
	color = (r & 0xFF) << 16 | (g & 0xFF) << 8 | (b & 0xFF);
	return (color);
}

static void		set_mandel(t_mandel *m, t_f *f)
{
	double		fx;
	double		fy;

	if (!m->init)
	{
		fx = 1;
		fy = 1;
		if (((double)X_WIN) / ((double)Y_WIN) < 2.7 / 2.4)
			fy = ((double)Y_WIN / 240) / ((double)X_WIN / 270);
		else
			fx = ((double)X_WIN / 270) / ((double)Y_WIN / 240);
		m->x1 = (-2.1 + 0.75) * fx - 0.75;
		m->x2 = (0.6 + 0.75) * fx - 0.75;
		m->y1 = -1.2 * fy;
		m->y2 = 1.2 * fy;
		m->init = 1;
	}
//	x = (((f->event.mouse.x * (m->x1 - m->x2)) / ((double)X_WIN)) * -1) + (m->x1 - m->x2) / 2.0 - 0.75;
//	y = (((f->event.mouse.y * (m->y1 - m->y2)) / ((double)Y_WIN))) - (m->y1 -m->y2) / 2.0;
	m->x1 = ((m->x1) / f->event.mouse.zoom) + f->event.key.tr_h;
	m->x2 = ((m->x2) / f->event.mouse.zoom) + f->event.key.tr_h;
	m->y1 = ((m->y1) / f->event.mouse.zoom) + f->event.key.tr_v;
	m->y2 = ((m->y2) / f->event.mouse.zoom) + f->event.key.tr_v;
	f->event.key.tr_h = 0;
	f->event.key.tr_v = 0;
	f->event.mouse.zoom = 1;
	m->ite_max = 50;
	m->img.ptr = mlx_new_image(f->mlx.ptr, X_WIN, Y_WIN);
	m->img.data = (int*)mlx_get_data_addr(m->img.ptr, &m->img.bpp,
			&m->img.lsize, &m->img.endian);
}

void			draw_mandelbrot(t_f *f, int repaint)
{
	static t_mandel		m;
	int					x;
	int					y;
	int					i;
	double				tmp;

	if (repaint == NEW)
	{
		set_mandel(&m, f);
		m.zx = X_WIN / (m.x2 - m.x1);
		m.zy = Y_WIN / (m.y2 - m.y1);
		x = 0;
		while(x < X_WIN)
		{
			y = 0;
			while (y < Y_WIN)
			{
				m.c_r = x / m.zx + m.x1;
				m.c_i = y / m.zy + m.y1;
				m.z_r = 0;
				m.z_i = 0;
				i = 0;
				while (i == 0 || (m.z_r * m.z_r + m.z_i * m.z_i < 4 && i < m.ite_max))
				{
					tmp = m.z_r;
					m.z_r = m.z_r * m.z_r - m.z_i * m.z_i + m.c_r;
					m.z_i = 2 * m.z_i * tmp + m.c_i;
					i++;
				}
				if (i != m.ite_max && check_draw(x, y, X_WIN, Y_WIN) == 1)
				{
					m.img.data[y * X_WIN + x] = set_color(m, i);
				}
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
