/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mandel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 06:04:15 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/31 02:34:10 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandelbrot.h"

int				key_mandel(int keycode, t_f *f)
{
	if (keycode == KEY_W)
	f->do_nothing = 0;
	if (keycode == KEY_UP)
	{
		f->flags.mandel_repaint = NEW;
		f->event.key.tr_v -= 0.1;
	}
	if (keycode == KEY_DW)
	{
		f->flags.mandel_repaint = NEW;
		f->event.key.tr_v += 0.1;
	}
	if (keycode == KEY_LEFT)
	{
		f->flags.mandel_repaint = NEW;
		f->event.key.tr_h += 0.1;
	}
	if (keycode == KEY_RIGHT)
	{
		f->flags.mandel_repaint = NEW;
		f->event.key.tr_h -= 0.1;
	}
	return (0);
}
