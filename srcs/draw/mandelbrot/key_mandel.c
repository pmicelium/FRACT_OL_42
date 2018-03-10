/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mandel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 06:04:15 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/10 23:02:39 by pmiceli          ###   ########.fr       */
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
	return (0);
}

void			mandel_key(t_mandel *m, t_f *f)
{
	static double		zoom = 50;

	if (f->event.key.ite < zoom)
		m->ite_max -= f->event.key.nb_ite;
	else
		m->ite_max += f->event.key.nb_ite;
	zoom = f->event.key.ite;
	if (m->ite_max <= 0)
		m->ite_max = 1;
	f->event.key.flag = 0;
}
