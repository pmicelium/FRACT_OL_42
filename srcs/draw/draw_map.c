/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 00:29:19 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/24 05:56:02 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void			draw_map(t_f *f, int fract)
{
	if (fract == MANDEL)
	{
		if (f->flags.mandel_repaint == 0)
			draw_mandelbrot(f, NEW);
		else
			draw_mandelbrot(f, REPAINT);
	}
	if (fract == JULIA)
	{
		if (f->flags.julia_repaint == 0)
			draw_julia(f, NEW);
		else
			draw_julia(f, REPAINT);
	}
/*
	if (fract == SHIP)
	{
		if (f->flags.ship_repaint == 0)
			draw_ship(f, NEW);
		else
			draw_julia(f, REPAINT);
	}
*/
}
