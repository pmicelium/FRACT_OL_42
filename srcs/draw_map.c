/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 00:29:19 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/24 04:46:34 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void			draw_map(t_f *f, int fract)
{
	f->do_nothing = 0;
	if (fract == MANDEL)
	{
		draw_mandelbrot(f, NEW);
	}
//	if (fract == JULIA)
//		draw_julia(f);
}
