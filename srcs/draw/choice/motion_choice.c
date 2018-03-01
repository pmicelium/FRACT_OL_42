/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_choice.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 03:49:08 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/24 05:36:54 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "choice.h"

static void		set_fr_null(t_f *f, int fr)
{
	if (fr == MANDEL)
		f->flags.fr.mandel = 1;
	else
		f->flags.fr.mandel = 0;
	if (fr == JULIA)
		f->flags.fr.julia = 1;
	else
		f->flags.fr.julia = 0;
	if (fr == SHIP)
		f->flags.fr.ship = 1;
	else
		f->flags.fr.ship = 0;
}

static void		display_select(t_f *f, int choice)
{
	if (choice == MANDEL)
		set_fr_null(f, MANDEL);
	else if (choice == JULIA)
		set_fr_null(f, JULIA);
	else if (choice == SHIP)
		set_fr_null(f, SHIP);
}

int				motion_choice(int x, int y, t_f *f)
{
	if (x < X_WIN / 3 && y > Y_WIN / 3)
		display_select(f, MANDEL);
	if (x > X_WIN / 3 && x < 2 * X_WIN / 3 && y > Y_WIN / 3)
		display_select(f, JULIA);
	if (x > 2 * X_WIN / 3 && x < X_WIN && y > Y_WIN / 3)
		display_select(f, SHIP);
	return (0);
}
