/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_mandel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 06:21:25 by pmiceli           #+#    #+#             */
/*   Updated: 2018/02/20 06:08:22 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandelbrot.h"

int				mouse_mandel(int button, int x, int y, t_f *f)
{
	if (button == WHEEL_UP || button == MOUSE_LF)
	{
		f->event.mouse.zoom += 10;
		f->flags.mandel_repaint = NEW;
		f->event.mouse.x = x;
		f->event.mouse.y = y;
	}
	if (button == WHEEL_DW || button == MOUSE_RG)
	{
		f->event.mouse.zoom -= 10;
		f->flags.mandel_repaint = NEW;
		f->event.mouse.x = x;
		f->event.mouse.y = y;
	}
	return (0);
}
