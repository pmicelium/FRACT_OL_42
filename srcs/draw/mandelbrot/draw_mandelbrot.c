/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 01:40:10 by pmiceli           #+#    #+#             */
/*   Updated: 2018/02/20 07:04:02 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandelbrot.h"

static int		set_color(t_mandel m, int i)
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

void			draw_mandelbrot(t_f *f, int repaint)
{
	static t_mandel		m;
	int					x;
	int					y;
	int					i;
	double				tmp;

	if (repaint == NEW)
	{
		m.img.ptr = mlx_new_image(f->mlx.ptr, X_WIN, Y_WIN);
		m.img.data = (int*)mlx_get_data_addr(m.img.ptr, &m.img.bpp, &m.img.lsize, &m.img.endian);

		m.x1 = -2.1;
		m.y1 = -1.2;
		m.x2 = 0.6;
		m.y2 = 1.2;

		m.ite_max = 50.0 + f->event.mouse.zoom / 10;

		m.zoom = X_WIN > Y_WIN ? (Y_WIN / 2.4) + f->event.mouse.zoom : X_WIN / 2.7 + f->event.mouse.zoom;
		m.image_x = (m.x2 - m.x1) * m.zoom;
		m.image_y = (m.y2 - m.y1) * m.zoom;
		x = 0;
		while (x < m.image_x)
		{
			y = 0;
			while (y < m.image_y)
			{
				m.c_r = X_WIN > Y_WIN ? x / m.zoom - 1.2 * ((double)X_WIN / (double)Y_WIN) : x / m.zoom - 1.35;
				m.c_i = X_WIN > Y_WIN ? y / m.zoom - 1.2 : y / m.zoom - 1.35 * ((double)Y_WIN / (double)X_WIN);
				m.z_r = 0;
				m.z_i = 0;
				i = 0;
				while ((m.z_r * m.z_r + m.z_i * m.z_i < 4 && i < m.ite_max) || i == 0)
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
