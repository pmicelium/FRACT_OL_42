/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_notify.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 03:53:48 by pmiceli           #+#    #+#             */
/*   Updated: 2018/02/06 02:21:15 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

static int		motion_fract(int x, int y, t_f *f)
{
	if (f->fract == MANDEL)
		motion_mandel(x, y, f);
	return (0);
}

int				motion_notify(int x, int y, t_f *f)
{
	if (f->flags.map == 0)
		motion_choice(x, y, f);
	motion_fract(x, y, f);
	return (0);
}
