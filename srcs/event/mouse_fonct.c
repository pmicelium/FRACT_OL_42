/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_fonct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 05:15:18 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/12 21:44:01 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

int				mouse_fonct(int button, int x, int y, t_f *f)
{
	if (f->fract == VOID)
		mouse_choice(button, x, y, f);
	else if (f->fract == MANDEL)
		mouse_mandel(button, x, y, f);
	else if (f->fract == JULIA)
		mouse_julia(button, x, y, f);
	else if (f->fract == SHIP)
		mouse_ship(button, x, y, f);
	else if (f->fract == HUGULUS)
		mouse_hugulus(button, x, y, f);
	return (0);
}
