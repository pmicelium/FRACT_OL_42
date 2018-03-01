/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ship.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 19:26:42 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/02 00:05:08 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ship.h"

static int		set_color(t_ship s, int i)
{
	int		color;
	int		r;
	int		g;
	int		b;

	color = 0;
	r = 0;
	g = 0;
	b = i * 255 / s.ite_max;
	color = (r & 0xFF) << 16 | (g & 0xFF) << 8 | (b & 0xFF);
	return (RED);
}

static t_ship	init_ship(t_ship s)
{
	s.fx = 1;
	s.fy = 1;
	if (((double)X_WIN) / ((double)Y_WIN) < 3.5 / 2.0)
		s.fy = ((double)Y_WIN / 200) / ((double)X_WIN / 350);
	else
		s.fx = ((double)X_WIN / 350) / ((double)Y_WIN / 200);
	s.x1 = -2.1 * s.fx;
	s.x2 = 1 * s.fx;
	s.y1 = -1 * s.fy;
	s.y2 = 1 * s.fy;
	s.zoom_x = X_WIN / (s.x2 - s.x1);
	s.zoom_y = Y_WIN / (s.y2 - s.y2);
	s.ite_max = 500.0;
	s.k = 1;
	s.init = 1;
	return (s);
}

void			draw_ship(t_f *f, int repaint)
{
	static t_ship	s;
	int				x;
	int				y;
	int				i;
	double			tmp;

	if (!s.init)
		s = init_ship(s);
	if (repaint == NEW)
	{
		s.img.ptr = mlx_new_image(f->mlx.ptr, X_WIN, Y_WIN);
		s.img.data = (int*)mlx_get_data_addr(s.img.ptr, &s.img.bpp,
				&s.img.lsize, &s.img.endian);
		x = 0;
		while (x < X_WIN)
		{
			y = 0;
			while (y < Y_WIN)
			{
				s.c_r = x / s.zoom_x + s.x1;
				s.c_i = y / s.zoom_y + s.y1;
				s.z_r = 0;
				s.z_i = 0;
				i = 0;
				while ((s.z_r * s.z_r + s.z_i * s.z_i < 4 && i < s.ite_max)
						|| i == 0)
				{
					tmp = s.z_r;
					s.z_r = ft_abs(s.z_r * s.z_r - s.z_i * s.z_i) + s.c_r;
					s.z_i = ft_abs(2 * s.z_i * tmp) + s.c_i;
					i++;
				}
				if (i != s.ite_max && check_draw(x, y, X_WIN, Y_WIN) == 1)
					s.img.data[y * X_WIN + x] = set_color(s, i);
				y++;
			}
			x++;
		}
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
