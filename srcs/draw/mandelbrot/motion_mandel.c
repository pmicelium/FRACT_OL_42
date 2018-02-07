/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_mandel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 02:21:18 by pmiceli           #+#    #+#             */
/*   Updated: 2018/02/06 03:11:23 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandelbrot.h"

int				motion_mandel(int x, int y, t_f *f)
{
	if (x && y)
		f->do_nothing = 0;
	f->event.motion.x = X_WIN - x;
	f->event.motion.y = y;
	f->flags.mandel_repaint = NEW;
	return (0);
}
