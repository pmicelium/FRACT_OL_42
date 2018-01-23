/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_fonct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 23:51:54 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/23 05:57:18 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int				key_fonct(int keycode, t_f *f)
{
	if (keycode == KEY_ESC)
	{
		ft_putendl_color("exiting ...", "green");
		if (f->flags.map == 0)
			display_choice(f, 2);
		mlx_clear_window(f->mlx.ptr, f->mlx.win);
		mlx_destroy_window(f->mlx.ptr, f->mlx.win);
		exit(1);
	}
	return (0);
}
