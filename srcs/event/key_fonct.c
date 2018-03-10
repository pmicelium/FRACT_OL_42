/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_fonct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 23:51:54 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/10 02:43:38 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

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
	return (0);
}
