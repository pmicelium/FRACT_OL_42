/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hugulus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 02:40:48 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/10 06:37:08 by pmiceli          ###   ########.fr       */
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
	return (0);
}

void			hugulus_key(t_hugulus *h, t_f *f)
{
	if (f->event.key.ite > 0)
		h->ite_max = f->event.key.ite;
	f->event.key.flag = 0;
}
