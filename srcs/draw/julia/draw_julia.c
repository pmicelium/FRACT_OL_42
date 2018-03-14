/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:41:01 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/14 22:23:34 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "julia.h"

static void		init_julia(t_julia *j, t_f *f)
{
	j->fx = 1;
	j->fy = 1;
	if (((double)X_WIN) / ((double)Y_WIN) < 200 / 240)
		j->fy = ((double)Y_WIN / 240) / ((double)X_WIN / 200);
	else
		j->fx = ((double)X_WIN / 200) / ((double)Y_WIN / 240);
	j->x1 = -1 * j->fx;
	j->x2 = 1 * j->fx;
	j->y1 = -1.2 * j->fy;
	j->y2 = 1.2 * j->fy;
	j->c_r = 0.285;
	j->c_i = 0.01;
	j->zoom_x = X_WIN / (j->x2 - j->x1);
	j->zoom_y = Y_WIN / (j->y2 - j->y1);
	j->k = 1;
	j->init = 1;
	j->init2 = 0;
	j->ite_max = f->event.key.ite;
	f->event.mouse.zoom /= 0.5;
}

static void		julia_calcul(t_julia *j, int x, int color)
{
	int					y;
	unsigned long		i;
	double				tmp;

	y = 0;
	while (y < Y_WIN)
	{
		j->z_r = x / j->zoom_x + j->x1;
		j->z_i = y / j->zoom_y + j->y1;
		i = 0;
		while ((j->z_r * j->z_r + j->z_i * j->z_i <= 4 && i < j->ite_max)
				|| i == 0)
		{
			tmp = j->z_r;
			j->z_r = (j->z_r * j->z_r) - (j->z_i * j->z_i) + j->c_r;
			j->z_i = 2 * j->z_i * tmp + j->c_i;
			i++;
		}
		if (i != j->ite_max && check_draw(x, y, X_WIN, Y_WIN) == 1)
			j->img.data[y * X_WIN + x] = color * (2 * i + 2);
		y++;
	}
	x++;
}

void			draw_julia(t_f *f, int repaint)
{
	static t_julia		j;

	if (!j.init)
		init_julia(&j, f);
	if (repaint == NEW)
	{
		init_img(&j.img, &f->mlx);
		j.x = -1;
		if (f->event.motion.flag == 1)
			change_c(&j, f);
		if (f->event.mouse.flag == 1 || j.init2 == 0)
			zoom_julia(&j, f);
		if (f->event.key.flag == 1)
			julia_key(&j, f);
		while (++j.x < X_WIN)
			julia_calcul(&j, j.x, f->color);
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
