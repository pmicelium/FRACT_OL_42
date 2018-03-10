/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_fonct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 05:15:18 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/10 02:15:43 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

int				mouse_fonct(int button, int x, int y, t_f *f)
{
	if (f->flags.map == 0)
		mouse_choice(button, x, y, f);
	else if (f->fract == MANDEL)
		mouse_mandel(button, x, y, f);
	else if (f->fract == JULIA)
		mouse_julia(button, x, y, f);
	else if (f->fract == SHIP)
		mouse_julia(button, x, y, f);
//	else if (f->fract == TREE)
//		mouse_tree(button, x, y, f);
	else if (f->fract == HUGULUS)
		mouse_hugulus(button, x, y, f);
	return (0);
}
