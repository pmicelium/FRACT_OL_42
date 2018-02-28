/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_fonct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 23:51:54 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/24 06:03:46 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

static void		key_fract(int keycode, t_f *f)
{
	if (f->fract == MANDEL)
		key_mandel(keycode, f);
}

int				key_fonct(int keycode, t_f *f)
{
	ft_putnbr_endl(keycode);
	if (keycode == KEY_ESC)
	{
		ft_putendl_color("exiting ...", "green");
		destroy_fract(f);
		mlx_clear_window(f->mlx.ptr, f->mlx.win);
		mlx_destroy_window(f->mlx.ptr, f->mlx.win);
		exit(1);
	}
	if (keycode == KEY_TILDE && f->flags.map == 1)
	{
		destroy_fract(f);
		mlx_clear_window(f->mlx.ptr, f->mlx.win);
	}
	if (f->flags.map != 0)
		key_fract(keycode, f);
	return (0);
}
