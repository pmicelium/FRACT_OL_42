/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_fonct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 05:15:18 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/23 05:17:27 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int				mouse_fonct(int button, int x, int y, t_f *f)
{
	if (f->flags.map == 0)
		mouse_choice(button, x, y, f);
	return (0);
}
