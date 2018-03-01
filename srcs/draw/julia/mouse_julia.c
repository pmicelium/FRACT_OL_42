/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:59:09 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/01 19:58:35 by pmiceli          ###   ########.fr       */
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
