/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_julia.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:18:06 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/15 18:30:14 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "julia.h"

int				key_julia(int keycode, t_f *f)
{
	if (keycode == KEY_PLUS)
	{
		f->event.key.ite++;
		f->event.key.flag = 1;
		f->flags.julia_repaint = NEW;
	}
	if (keycode == KEY_MINUS)
	{
		f->event.key.ite--;
		f->event.key.flag = 1;
		f->flags.julia_repaint = NEW;
	}
	if (keycode == KEY_W || keycode == KEY_S)
	{
		f->event.key.tr_v = keycode == KEY_W ? 1 : -1;
		f->event.key.flag = 2;
		f->flags.julia_repaint = NEW;
	}
	if (keycode == KEY_A || keycode == KEY_D)
	{
		f->event.key.tr_h = keycode == KEY_A ? 1 : -1;
		f->event.key.flag = 2;
		f->flags.julia_repaint = NEW;
	}
	return (0);
}

void			julia_key(t_julia *j, t_f *f)
{
	if (f->event.key.flag == 1)
	{
		j->ite_max = f->event.key.ite;
		if (j->ite_max <= 0)
			j->ite_max = 1;
	}
	if (f->event.key.flag == 2)
	{
		if (f->event.key.tr_v != 0)
		{
			j->y1 = f->event.key.tr_v == -1 ? j->y1 + RATIO_V : j->y1 - RATIO_V;
			j->y2 = f->event.key.tr_v == -1 ? j->y2 - RATIO_V : j->y2 + RATIO_V;
		}
		if (f->event.key.tr_h != 0)
		{
			j->x1 = f->event.key.tr_h == -1 ? j->x1 + RATIO_H : j->x1 - RATIO_H;
			j->x2 = f->event.key.tr_h == -1 ? j->x2 - RATIO_H : j->x2 + RATIO_H;
		}
		f->event.key.tr_v = 0;
		f->event.key.tr_h = 0;
	}
	f->event.key.flag = 0;
}
