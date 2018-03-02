/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:57:39 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/02 00:31:23 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "julia.h"

int				motion_julia(int x, int y, t_f *f)
{
	if (x != y)
		f->do_nothing = 0;
	if (f->event.motion.flag == 1)
	{
		f->event.motion.x = x;
		f->event.motion.y = y;
		f->flags.julia_repaint = NEW;
	}
	return (0);
}
