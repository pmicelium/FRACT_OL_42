/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hugulus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 01:46:18 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/10 01:47:12 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hugulus.h"

int				mouse_hugulus(int button, int x, int y, t_f *f)
{
	if (button == WHEEL_PRESS)
	{
		if (f->event.motion.flag == 1)
			f->event.motion.flag = 0;
		else
			f->event.motion.flag = 1;
		f->flags.hugulus_repaint = NEW;
	}
	if (button == WHEEL_UP || button == MOUSE_LF)
	{
		f->event.mouse.zoom *= 0.5;
		f->flags.hugulus_repaint = NEW;
		f->event.mouse.x = x;
		f->event.mouse.y = y;
		f->event.mouse.flag = 1;
	}
	if (button == WHEEL_DW || button == MOUSE_RG)
	{
		f->event.mouse.zoom /= 0.5;
		f->flags.hugulus_repaint = NEW;
		f->event.mouse.x = x;
		f->event.mouse.y = y;
		f->event.mouse.flag = 1;
	}
	return (0);
}
