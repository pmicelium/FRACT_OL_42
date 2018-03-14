/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hugulus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 01:36:34 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/14 20:23:35 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hugulus.h"

static void		init_hugulus(t_hugulus *h, t_f *f)
{
	h->fx = 1;
	h->fy = 1;
	if (((double)X_WIN) / ((double)Y_WIN) < 200 / 240)
		h->fy = ((double)Y_WIN / 240) / ((double)X_WIN / 200);
	else
		h->fx = ((double)X_WIN / 200) / ((double)Y_WIN / 240);
	h->x1 = -1 * h->fx;
	h->x2 = 1 * h->fx;
	h->y1 = -1.2 * h->fy;
	h->y2 = 1.2 * h->fy;
	h->c_r = 0.285;
	h->c_r = -0.8;
	h->zoom_x = X_WIN / (h->x2 - h->x1);
	h->zoom_y = Y_WIN / (h->y2 - h->y1);
	h->k = 1;
	h->init = 1;
	h->init2 = 0;
	h->ite_max = f->event.key.ite;
	f->event.mouse.zoom /= 0.25;
}

static void		zoom_hugulus(t_hugulus *h, t_f *f)
{
	double				x_zoom;
	double				y_zoom;

	x_zoom = f->event.mouse.x / h->zoom_x + h->x1;
	y_zoom = f->event.mouse.y / h->zoom_y + h->y1;
	h->x1 = x_zoom - f->event.mouse.zoom * h->fx;
	h->x2 = x_zoom + f->event.mouse.zoom * h->fx;
	h->y1 = y_zoom - f->event.mouse.zoom * h->fy;
	h->y2 = y_zoom + f->event.mouse.zoom * h->fy;
	h->zoom_x = X_WIN / (h->x2 - h->x1);
	h->zoom_y = Y_WIN / (h->y2 - h->y1);
	f->event.mouse.flag = 0;
	h->init2 = 1;
}

static void		hugulus_calcul(t_hugulus *h, int x)
{
	unsigned long		i;
	double				tmp;
	int					y;

	y = 0;
	while (y < Y_WIN)
	{
		h->z_r = x / h->zoom_x + h->x1;
		h->z_i = y / h->zoom_y + h->y1;
		i = 0;
		while ((h->z_r * h->z_r + h->z_i * h->z_i <= 4 && i < h->ite_max)
				|| i == 0)
		{
			tmp = h->z_r;
			h->z_r = (h->z_r * h->z_r) - (h->z_i * h->z_i) + h->c_r;
			h->z_i = 2 * h->z_i * tmp + h->c_i;
			i++;
		}
		if (i != h->ite_max && check_draw(x, y, X_WIN, Y_WIN) == 1)
			h->img.data[y * X_WIN + x] = h->color * (2 * i + 2);
		y++;
	}
	x++;
}

void			draw_hugulus(t_f *f, int repaint)
{
	static t_hugulus	h;
	int					x;

	if (!h.init)
		init_hugulus(&h, f);
	if (repaint == NEW)
	{
		init_img(&h.img, &f->mlx);
		x = -1;
		if (f->event.mouse.flag == 1 || h.init2 == 0)
			zoom_hugulus(&h, f);
		if (f->event.key.flag == 1)
			hugulus_key(&h, f);
		h.color = f->color;
		while (++x < X_WIN)
			hugulus_calcul(&h, x);
	}
	if (repaint == REPAINT || repaint == NEW)
		mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, h.img.ptr, 0, 0);
	f->flags.hugulus_repaint = 1;
	if (repaint == DESTROY)
	{
		h.init = 0;
		mlx_destroy_image(f->mlx.ptr, h.img.ptr);
	}
}
