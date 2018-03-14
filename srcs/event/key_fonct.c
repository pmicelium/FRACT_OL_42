/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_fonct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 23:51:54 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/14 23:59:06 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

static void		color_repaint(t_f *f)
{
	f->flags.mandel_repaint = f->fract == MANDEL ? 0 : 1;
	f->flags.julia_repaint = f->fract == JULIA ? 0 : 1;
	f->flags.ship_repaint = f->fract == SHIP ? 0 : 1;
	f->flags.hugulus_repaint = f->fract == HUGULUS ? 0 : 1;
}

static void		key_change(int keycode, t_f *f)
{
	if (keycode == KEY_1)
		f->color = 0x889499;
	else if (keycode == KEY_2)
		f->color = 0x788757;
	else if (keycode == KEY_3)
		f->color = 0x948977;
	else if (keycode == KEY_4)
		f->color = 0x766564;
	color_repaint(f);
}

static void		key_fract(int keycode, t_f *f)
{
	if (f->fract == MANDEL)
		key_mandel(keycode, f);
	else if (f->fract == JULIA)
		key_julia(keycode, f);
	else if (f->fract == SHIP)
		key_ship(keycode, f);
	else if (f->fract == HUGULUS)
		key_hugulus(keycode, f);
}

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
	else if (keycode == KEY_TILDE && f->fract != VOID)
	{
		destroy_fract(f);
		mlx_clear_window(f->mlx.ptr, f->mlx.win);
	}
	else if (f->fract != VOID)
		key_fract(keycode, f);
	if (keycode == KEY_1 || keycode == KEY_2 || keycode == KEY_3 ||
			keycode == KEY_4)
		key_change(keycode, f);
	if (keycode == KEY_H)
		f->help.flag = f->help.flag == 0 ? 1 : 0;
	return (0);
}
