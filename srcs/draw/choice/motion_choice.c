/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_choice.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 03:49:08 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/10 06:05:24 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "choice.h"

static void		display_select(t_f *f, int fr)
{
	f->flags.fr.mandel = fr == MANDEL ? 1 : 0;
	f->flags.fr.julia = fr == JULIA ? 1 : 0;
	f->flags.fr.ship = fr == SHIP ? 1 : 0;
	f->flags.fr.tree = fr == TREE ? 1 : 0;
	f->flags.fr.hugulus = fr == HUGULUS ? 1 : 0;
	f->flags.fr._void = fr == VOID ? 1 : 0;
}

int				motion_choice(int x, int y, t_f *f)
{
	if (x < X_WIN / 4 && y > Y_WIN / 3 && y < Y_WIN / 4 + 350)
		display_select(f, MANDEL);
	else if (x > X_WIN / 4 && x < 2 * X_WIN / 4 && y > Y_WIN / 3 &&
			y < Y_WIN / 4 + 350)
		display_select(f, JULIA);
	else if (x > 2 * X_WIN / 4 && x < 3 * X_WIN / 4 && y > Y_WIN / 3 &&
			y < Y_WIN / 4 + 350)
		display_select(f, SHIP);
	else if (x > 3 * X_WIN / 4 && x < X_WIN && y > Y_WIN / 3 &&
			y < Y_WIN / 4 + 350)
		display_select(f, TREE);
	else if (x < X_WIN / 4 && y > Y_WIN / 4 + 350 && y < Y_WIN)
		display_select(f, HUGULUS);
	else
		display_select(f, VOID);
	return (0);
}
