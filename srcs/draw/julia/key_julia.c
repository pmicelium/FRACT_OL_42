/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_julia.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:18:06 by pmiceli           #+#    #+#             */
/*   Updated: 2018/02/28 20:24:17 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "julia.h"

int				key_julia(int keycode, t_f *f)
{
	if (keycode == KEY_PLUS)
	{
		f->event.key.ite ++;
		f->event.key.flag = 1;
		f->flags.julia_repaint = NEW;
	}
	if (keycode == KEY_MINUS)
	{
		f->event.key.ite --;
		f->event.key.flag = 1;
		f->flags.julia_repaint = NEW;
	}
	return (0);
}
