/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_fract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 04:52:09 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/12 21:31:00 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void			destroy_fract(t_f *f)
{
	if (f->fract == VOID)
		display_choice(f, DESTROY);
	else if (f->fract == MANDEL)
		draw_mandelbrot(f, DESTROY);
	else if (f->fract == JULIA)
		draw_julia(f, DESTROY);
	else if (f->fract == SHIP)
		draw_ship(f, DESTROY);
	else if (f->fract == HUGULUS)
		draw_hugulus(f, DESTROY);
	set_var(f);
	mlx_clear_window(f->mlx.ptr, f->mlx.win);
}
