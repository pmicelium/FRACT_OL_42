/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:59:09 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/12 21:33:20 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "julia.h"

int				mouse_julia(int button, int x, int y, t_f *f)
{
	if (button == WHEEL_PRESS)
	{
		if (f->event.motion.flag == 1)
			f->event.motion.flag = 0;
		else
			f->event.motion.flag = 1;
		f->flags.julia_repaint = NEW;
	}
	if (button == WHEEL_UP || button == MOUSE_LF)
	{
		f->event.mouse.zoom *= 0.5;
		f->flags.julia_repaint = NEW;
		f->event.mouse.x = x;
		f->event.mouse.y = y;
		f->event.mouse.flag = 1;
	}
	if (button == WHEEL_DW || button == MOUSE_RG)
	{
		f->event.mouse.zoom /= 0.5;
		f->flags.julia_repaint = NEW;
		f->event.mouse.x = x;
		f->event.mouse.y = y;
		f->event.mouse.flag = 1;
	}
	return (0);
}

void			zoom_julia(t_julia *j, t_f *f)
{
	double				x_zoom;
	double				y_zoom;

	x_zoom = f->event.mouse.x / j->zoom_x + j->x1;
	y_zoom = f->event.mouse.y / j->zoom_y + j->y1;
	j->x1 = x_zoom - f->event.mouse.zoom * j->fx;
	j->x2 = x_zoom + f->event.mouse.zoom * j->fx;
	j->y1 = y_zoom - f->event.mouse.zoom * j->fy;
	j->y2 = y_zoom + f->event.mouse.zoom * j->fy;
	j->zoom_x = X_WIN / (j->x2 - j->x1);
	j->zoom_y = Y_WIN / (j->y2 - j->y1);
	j->init2 = 1;
	f->event.mouse.flag = 0;
}
