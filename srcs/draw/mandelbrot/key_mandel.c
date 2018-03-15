/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mandel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 06:04:15 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/15 18:21:08 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandelbrot.h"

int				key_mandel(int keycode, t_f *f)
{
	if (keycode == KEY_PLUS)
	{
		f->event.key.ite++;
		f->event.key.flag = 1;
		f->flags.mandel_repaint = NEW;
	}
	if (keycode == KEY_MINUS)
	{
		f->event.key.ite--;
		f->event.key.flag = 1;
		f->flags.mandel_repaint = NEW;
	}
	if (keycode == KEY_W || keycode == KEY_S)
	{
		f->event.key.tr_v = keycode == KEY_W ? 1 : -1;
		f->event.key.flag = 2;
		f->flags.mandel_repaint = NEW;
	}
	if (keycode == KEY_A || keycode == KEY_D)
	{
		f->event.key.tr_h = keycode == KEY_A ? 1 : -1;
		f->event.key.flag = 2;
		f->flags.mandel_repaint = NEW;
	}
	return (0);
}

void			mandel_key(t_mandel *m, t_f *f)
{
	if (f->event.key.flag == 1)
	{
		m->ite_max = f->event.key.ite;
		if (m->ite_max <= 0)
			m->ite_max = 1;
	}
	if (f->event.key.flag == 2)
	{
		if (f->event.key.tr_v != 0)
		{
			m->y1 = f->event.key.tr_v == -1 ? m->y1 + RATIO_V : m->y1 - RATIO_V;
			m->y2 = f->event.key.tr_v == -1 ? m->y2 - RATIO_V : m->y2 + RATIO_V;
		}
		if (f->event.key.tr_h != 0)
		{
			m->x1 = f->event.key.tr_h == -1 ? m->x1 + RATIO_H : m->x1 - RATIO_H;
			m->x2 = f->event.key.tr_h == -1 ? m->x2 - RATIO_H : m->x2 + RATIO_H;
		}
		f->event.key.tr_v = 0;
		f->event.key.tr_h = 0;
	}
	f->event.key.flag = 0;
}
