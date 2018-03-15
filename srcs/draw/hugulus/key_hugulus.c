/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hugulus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 02:40:48 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/15 18:31:53 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hugulus.h"

int				key_hugulus(int keycode, t_f *f)
{
	if (keycode == KEY_PLUS)
	{
		f->event.key.ite++;
		f->event.key.flag = 1;
		f->flags.hugulus_repaint = NEW;
	}
	if (keycode == KEY_MINUS)
	{
		f->event.key.ite--;
		f->event.key.flag = 1;
		f->flags.hugulus_repaint = NEW;
	}
	if (keycode == KEY_W || keycode == KEY_S)
	{
		f->event.key.tr_v = keycode == KEY_W ? 1 : -1;
		f->event.key.flag = 2;
		f->flags.hugulus_repaint = NEW;
	}
	if (keycode == KEY_A || keycode == KEY_D)
	{
		f->event.key.tr_h = keycode == KEY_A ? 1 : -1;
		f->event.key.flag = 2;
		f->flags.hugulus_repaint = NEW;
	}
	return (0);
}

void			hugulus_key(t_hugulus *h, t_f *f)
{
	if (f->event.key.flag == 1)
	{
		h->ite_max = f->event.key.ite;
		if (h->ite_max <= 0)
			h->ite_max = 1;
	}
	if (f->event.key.flag == 2)
	{
		if (f->event.key.tr_v != 0)
		{
			h->y1 = f->event.key.tr_v == -1 ? h->y1 + RATIO_V : h->y1 - RATIO_V;
			h->y2 = f->event.key.tr_v == -1 ? h->y2 - RATIO_V : h->y2 + RATIO_V;
		}
		if (f->event.key.tr_h != 0)
		{
			h->x1 = f->event.key.tr_h == -1 ? h->x1 + RATIO_H : h->x1 - RATIO_H;
			h->x2 = f->event.key.tr_h == -1 ? h->x2 - RATIO_H : h->x2 + RATIO_H;
		}
		f->event.key.tr_v = 0;
		f->event.key.tr_h = 0;
	}
	f->event.key.flag = 0;
}
