/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mandel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 06:04:15 by pmiceli           #+#    #+#             */
/*   Updated: 2018/02/20 06:46:52 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandelbrot.h"

//pas encore de translation dans le mandelbrot

int				key_mandel(int keycode, t_f *f)
{
	if (keycode == KEY_W)
		f->do_nothing = 0;
	if (keycode == KEY_UP)
	{
		f->flags.mandel_repaint = NEW;
		f->event.key.tr_v += 1.0;
	}
	if (keycode == KEY_DW)
	{
		f->flags.mandel_repaint = NEW;
		f->event.key.tr_v -= 1.0;
	}
	if (keycode == KEY_LEFT)
	{
		f->flags.mandel_repaint = NEW;
		f->event.key.tr_h += 1.0;
	}
	if (keycode == KEY_RIGHT)
	{
		f->flags.mandel_repaint = NEW;
		f->event.key.tr_h -= 1.0;
	}
	return (0);
}
