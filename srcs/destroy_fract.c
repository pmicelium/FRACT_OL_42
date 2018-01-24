/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_fract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 04:52:09 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/24 05:02:46 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void			destroy_fract(t_f *f)
{
	if (f->flags.map == 0)
		display_choice(f, DESTROY);
	else if (f->fract == MANDEL)
	{
		draw_mandelbrot(f, DESTROY);
		set_var(f);
	}
}
