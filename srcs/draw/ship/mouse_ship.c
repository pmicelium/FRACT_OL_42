/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_ship.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 19:26:53 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/02 01:58:06 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ship.h"

int				mouse_ship(int button, int x, int y, t_f *f)
{
	if (button == WHEEL_UP || button == MOUSE_LF)
	{
		f->event.mouse.zoom *= 0.5;
		f->flags.mandel_repaint = NEW;
		f->event.mouse.x = x;
		f->event.mouse.y = y;
		f->event.mouse.flag = 1;
	}
	if (button == WHEEL_DW || button == MOUSE_RG)
	{
		f->event.mouse.zoom /= 0.5;
		f->flags.mandel_repaint = NEW;
		f->event.mouse.x = x;
		f->event.mouse.y = y;
		f->event.mouse.flag = 1;
	}
	return (0);

}
