/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_choice.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 03:49:08 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/14 22:17:34 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "choice.h"

static void		display_select(t_f *f, int fr)
{
	f->flags.fr.mandel = fr == MANDEL ? 1 : 0;
	f->flags.fr.julia = fr == JULIA ? 1 : 0;
	f->flags.fr.ship = fr == SHIP ? 1 : 0;
	f->flags.fr.hugulus = fr == HUGULUS ? 1 : 0;
	f->flags.fr.voidd = fr == VOID ? 1 : 0;
}

int				motion_choice(int x, int y, t_f *f)
{
	if (x < X_WIN / 2 && y < CROSS_Y && y > Y_WIN / 3)
		display_select(f, MANDEL);
	else if (x > X_WIN / 2 && y < CROSS_Y && y > Y_WIN / 3)
		display_select(f, JULIA);
	else if (x < X_WIN / 2 && y > CROSS_Y)
		display_select(f, SHIP);
	else if (x > X_WIN / 2 && y > CROSS_Y)
		display_select(f, HUGULUS);
	else
		display_select(f, VOID);
	return (0);
}
