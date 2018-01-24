/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_mandel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 06:21:25 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/24 06:46:57 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandelbrot.h"

int				mouse_mandel(int button, int x, int y, t_f *f)
{
	if (button == WHEEL_UP)
	{
		f->event.mouse.zoom++;
		f->flags.mandel_repaint = NEW;
		f->event.mouse.x = x;
		f->event.mouse.y = y;
	}
	if (button == WHEEL_DW)
	{
		f->event.mouse.zoom--;
		if (f->event.mouse.zoom == 0)
			f->event.mouse.zoom++;
		f->flags.mandel_repaint = NEW;
		f->event.mouse.x = x;
		f->event.mouse.y = y;
	}
	return (0);
}
