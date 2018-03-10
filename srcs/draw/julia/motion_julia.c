/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:57:39 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/10 23:17:20 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "julia.h"

int				motion_julia(int x, int y, t_f *f)
{
	if (f->event.motion.flag == 1)
	{
		f->event.motion.x = x;
		f->event.motion.y = y;
		f->flags.julia_repaint = NEW;
	}
	return (0);
}

void			change_c(t_julia *j, t_f *f)
{
	j->c_r = (((f->event.motion.x * (j->x2 - j->x1)) / ((double)X_WIN)))
		- (j->x2 - j->x1) / 2.0;
	j->c_i = (((f->event.motion.y * (j->y2 - j->y1)) / ((double)Y_WIN)))
		- (j->y2 - j->y1) / 2.0;
	f->event.motion.flag = 1;
}
