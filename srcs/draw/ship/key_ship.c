/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ship.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 19:26:57 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/15 18:26:40 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ship.h"

int				key_ship(int keycode, t_f *f)
{
	if (keycode == KEY_PLUS)
	{
		f->event.key.ite++;
		f->event.key.flag = 1;
		f->flags.ship_repaint = NEW;
	}
	if (keycode == KEY_MINUS)
	{
		f->event.key.ite--;
		f->event.key.flag = 1;
		f->flags.ship_repaint = NEW;
	}
	if (keycode == KEY_W || keycode == KEY_S)
	{
		f->event.key.tr_v = keycode == KEY_W ? 1 : -1;
		f->event.key.flag = 2;
		f->flags.ship_repaint = NEW;
	}
	if (keycode == KEY_A || keycode == KEY_D)
	{
		f->event.key.tr_h = keycode == KEY_A ? 1 : -1;
		f->event.key.flag = 2;
		f->flags.ship_repaint = NEW;
	}
	return (0);
}

void			ship_key(t_ship *s, t_f *f)
{
	if (f->event.key.flag == 1)
	{
		s->ite_max = f->event.key.ite;
		if (s->ite_max <= 0)
			s->ite_max = 1;
	}
	if (f->event.key.flag == 2)
	{
		if (f->event.key.tr_v != 0)
		{
			s->y1 = f->event.key.tr_v == -1 ? s->y1 + RATIO_V : s->y1 - RATIO_V;
			s->y2 = f->event.key.tr_v == -1 ? s->y2 - RATIO_V : s->y2 + RATIO_V;
		}
		if (f->event.key.tr_h != 0)
		{
			s->x1 = f->event.key.tr_h == -1 ? s->x1 + RATIO_H : s->x1 - RATIO_H;
			s->x2 = f->event.key.tr_h == -1 ? s->x2 - RATIO_H : s->x2 + RATIO_H;
		}
		f->event.key.tr_v = 0;
		f->event.key.tr_h = 0;
	}
	f->event.key.flag = 0;
}
