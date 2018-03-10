/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 00:29:19 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/10 05:10:18 by pmiceli          ###   ########.fr       */
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
	else if (fract == JULIA)
	{
		if (f->flags.julia_repaint == 0)
			draw_julia(f, NEW);
		else
			draw_julia(f, REPAINT);
	}
	else if (fract == SHIP)
	{
		if (f->flags.ship_repaint == 0)
			draw_ship(f, NEW);
		else
			draw_ship(f, REPAINT);
	}
	else if (fract == HUGULUS)
	{
		if (f->flags.hugulus_repaint == 0)
			draw_hugulus(f, NEW);
		else
			draw_hugulus(f, REPAINT);
	}
	else if (fract == VOID)
	{
		if (f->flags.display_repaint == 0)
			display_choice(f, NEW);
		else
			display_choice(f, REPAINT);
	}
//	else if (fract == TREE)
//	{
//		if (f->flags.tree_repaint == 0)
//			draw_tree(f, NEW);
//		else
//			draw_tree(f, REPAINT);
//	}
}
