/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_fonct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 05:15:18 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/24 06:40:45 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

static void		mouse_fract(int button, int x, int y, t_f *f)
{
	if (f->fract == MANDEL)
		mouse_mandel(button, x, y, f);
}

int				mouse_fonct(int button, int x, int y, t_f *f)
{
	if (f->flags.map == 0)
		mouse_choice(button, x, y, f);
	else
		mouse_fract(button, x, y, f);
	return (0);
}
