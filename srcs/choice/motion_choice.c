/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_choice.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 03:49:08 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/23 05:19:28 by pmiceli          ###   ########.fr       */
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
}

static void		display_select(t_f *f, int choice)
{
	if (choice == MANDEL)
		set_fr_null(f, MANDEL);
	else if (choice == JULIA)
		set_fr_null(f, JULIA);
}

int				motion_choice(int x, int y, t_f *f)
{
//	printf("x : %d, y : %d\n", x, y);
	if (x < 600 && y > Y_WIN / 3)
		display_select(f, MANDEL);
	if (x > 600 && x < 1200 && y > Y_WIN / 3)
		display_select(f, JULIA);
	return (0);
}
