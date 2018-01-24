/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_fonct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 23:51:54 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/24 05:08:04 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

int				key_fonct(int keycode, t_f *f)
{
	if (keycode == KEY_ESC)
	{
		ft_putendl_color("exiting ...", "green");
		destroy_fract(f);
		mlx_clear_window(f->mlx.ptr, f->mlx.win);
		mlx_destroy_window(f->mlx.ptr, f->mlx.win);
		exit(1);
	}
	if (keycode == 50 && f->flags.map == 1)
	{
		destroy_fract(f);
		mlx_clear_window(f->mlx.ptr, f->mlx.win);
	}
	return (0);
}
