/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_choice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 05:20:29 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/14 22:19:06 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "choice.h"

int				mouse_choice(int button, int x, int y, t_f *f)
{
	if (button == MOUSE_LF && x < X_WIN / 2 && y < CROSS_Y && y > Y_WIN / 3)
		f->fract = MANDEL;
	if (button == MOUSE_LF && x > X_WIN / 2 && y < CROSS_Y && y > Y_WIN / 3)
		f->fract = JULIA;
	if (button == MOUSE_LF && x < X_WIN / 2 && y > CROSS_Y)
		f->fract = SHIP;
	if (button == MOUSE_LF && x > X_WIN / 2 && y > CROSS_Y)
		f->fract = HUGULUS;
	if (f->fract != VOID)
		display_choice(f, DESTROY);
	return (0);
}
