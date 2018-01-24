/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 01:40:10 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/24 04:47:22 by pmiceli          ###   ########.fr       */
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
//	r = 0;
	r = i * 255 / m.ite_max;
	g = 0;
//	b = i * 255 / m.ite_max;
	b = 0;
	color = (r & 0xFF) << 16 | (g & 0xFF) << 8 | (b & 0xFF);
	return (color);
}

static void		set_mandel(t_mandel *m, t_f *f)
{
	m->x1 = -2.1;
	m->x2 = 0.6;
	m->y1 = -1.2;
	m->y2 = 1.2;
//	m->zoom = 100;
	m->ite_max = 50;
//	m->image_x = (m->x2 - m->x1) * m->zoom;
	m->image_x = X_WIN;
//	m->image_y = (m->y2 - m->y1) * m->zoom;
	m->image_y = Y_WIN;
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
	double				zx;
	double				zy;

	if (repaint == NEW)
	{
		set_mandel(&m, f);
		zx = m.image_x / (m.x2 - m.x1);
		zy = m.image_y / (m.y2 - m.y1);
		x = 0;
		while(x < m.image_x)
		{
			y = 0;
			while (y < m.image_y)
			{
				m.c_r = x / zx + m.x1;
				m.c_i = y / zy + m.y1;
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
				if (i != m.ite_max)
				{
					m.img.data[y * X_WIN + x] = set_color(m, i);
				}
				y++;
			}
		x++;
		}
		mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, m.img.ptr, 0, 0);
	}
	if (repaint == DESTROY)
	{
		mlx_destroy_image(f->mlx.ptr, m.img.ptr);
	}
}