/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 00:51:45 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/23 03:33:49 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int				loop_hook(t_f *f)
{
	mlx_clear_window(f->mlx.ptr, f->mlx.win);
	if (f->flags.map == 0)
	{
		if (f->flags.display_repaint == 0)
			display_choice(f, 0);
		else
			display_choice(f, 1);
	}
	return (0);
}
