/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_mandel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 06:21:25 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/30 03:11:08 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandelbrot.h"

int				mouse_mandel(int button, int x, int y, t_f *f)
{
	if (x == 0 && y == 1)
		f->do_nothing = 0;
	if (button == WHEEL_UP)
	{
		f->event.mouse.zoom += 0.2;
		f->flags.mandel_repaint = NEW;
		f->event.mouse.x = x;
		f->event.mouse.y = y;
	}
	if (button == WHEEL_DW)
	{
		f->event.mouse.zoom -= 0.2;
		f->flags.mandel_repaint = NEW;
		f->event.mouse.x = x;
		f->event.mouse.y = y;
	}
	if (button == MOUSE_ONE)
	{
		printf("mx : %d, my : %d\n", x, y);
		f->event.mouse.x = x;
		f->event.mouse.y = y;
		f->flags.mandel_repaint = NEW;
	}
	return (0);
}
