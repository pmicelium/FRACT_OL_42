/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 01:40:10 by pmiceli           #+#    #+#             */
/*   Updated: 2018/02/26 23:29:19 by pmiceli          ###   ########.fr       */
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
	m.x1 = -2.1;
	m.x2 = 0.6;
	m.y1 = -1.2;
	m.y2 = 1.2;
	m.zoom_x = X_WIN / (m.x2 - m.x1);
	m.zoom_y = Y_WIN / (m.y2 - m.y1);
	m.ite_max = 50.0;
	m.k = 0.78;
	return (m);
}

void				draw_mandelbrot(t_f *f, int repaint)
{
	static t_mandel		m;
	int					x;
	int					y;
	int					i;
	double				x_zoom;
	double				y_zoom;
	double				tmp;

	if (!m.x1)
		m = mandel_init(m);
	if (repaint == NEW)
	{
		m.img.ptr = mlx_new_image(f->mlx.ptr, X_WIN, Y_WIN);
		m.img.data = (int*)mlx_get_data_addr(m.img.ptr, &m.img.bpp,
				&m.img.lsize, &m.img.endian);
		x = 0;
		x_zoom = f->event.mouse.x / m.zoom_x + m.x1;
		y_zoom = f->event.mouse.y / m.zoom_y + m.y1;
		m.x1 = x_zoom - f->event.mouse.zoom;
		m.x2 = x_zoom + f->event.mouse.zoom;
		m.y1 = y_zoom - f->event.mouse.zoom;
		m.y2 = y_zoom + f->event.mouse.zoom;
		m.zoom_x = X_WIN / (m.x2 - m.x1);
		m.zoom_y = Y_WIN / (m.y2 - m.y1);
		m.ite_max += f->event.key.nb_ite;
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
					m.z_i = 2 * m.z_i * tmp +  m.c_i;
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
