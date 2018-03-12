/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_choice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 05:20:29 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/12 21:54:35 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "choice.h"

int				mouse_choice(int button, int x, int y, t_f *f)
{
	if (button == MOUSE_LF && x < X_WIN / 4 && y > Y_WIN / 3 && y < Y_WIN / 4
			+ 350)
		f->fract = MANDEL;
	if (button == MOUSE_LF && x > X_WIN / 4 && x < 2 * X_WIN / 4 &&
			y > Y_WIN / 3 && y < Y_WIN / 4 + 350)
		f->fract = JULIA;
	if (button == MOUSE_LF && x > 2 * X_WIN / 4 && x < 3 * X_WIN / 4 &&
			y > Y_WIN / 3 && y < Y_WIN / 4 + 350)
		f->fract = SHIP;
	if (button == MOUSE_LF && x < X_WIN / 4 && y > Y_WIN / 4 + 350 && y < Y_WIN)
		f->fract = HUGULUS;
	if (f->fract != VOID)
		display_choice(f, DESTROY);
	return (0);
}
