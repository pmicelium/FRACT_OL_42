/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:59:09 by pmiceli           #+#    #+#             */
/*   Updated: 2018/02/28 22:49:31 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "julia.h"

int				mouse_julia(int button, int x, int y, t_f *f)
{
	if (button == MOUSE_RG)
	{
		if (f->event.motion.flag == 1)
			f->event.motion.flag = 0;
		else
			f->event.motion.flag = 1;
		f->flags.julia_repaint = NEW;
	}
	if (button == WHEEL_UP)
	{
		f->event.mouse.zoom *= 0.5;
		f->flags.julia_repaint = NEW;
		f->event.mouse.x = x;
		f->event.mouse.y = y;
		f->event.mouse.flag = 1;
	}
	if (button == WHEEL_DW)
	{
		f->event.mouse.zoom /= 0.5;
		f->flags.julia_repaint = NEW;
		f->event.mouse.x = x;
		f->event.mouse.y = y;
		f->event.mouse.flag = 1;
	}
	return (0);
}
