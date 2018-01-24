/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_choice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 05:20:29 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/24 03:18:33 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "choice.h"

int				mouse_choice(int button, int x, int y, t_f *f)
{
	if (button == 1 && x < 600 & y > Y_WIN / 3)
	{
		f->fract = MANDEL;
		f->flags.map = 1;
		ft_putendl("Mandelbrot");
		display_choice(f, 2);
	}
	if (button == 1 && x > 600 && x < 1200 && y > Y_WIN / 3)
	{
		f->fract = JULIA;
		f->flags.map = 1;
		ft_putendl("julia");
		display_choice(f, 2);
	}
	return (0);
}
