/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_choice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 05:19:35 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/12 22:08:49 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "choice.h"

static void		fill_image(int *img, int x, int y, int color)
{
	int i;
	int j;

	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			img[j * x + i] = color;
			i++;
		}
		j++;
	}
}

static void		put_choice(t_f *f)
{
	if (f->flags.fr.mandel == 1)
		mlx_string_put(f->mlx.ptr, f->mlx.win, MAN_X - 20, MAN_Y,
				GREY, ">            <");
	mlx_string_put(f->mlx.ptr, f->mlx.win, MAN_X, MAN_Y, GREY, "Mandelbrot");
	if (f->flags.fr.julia == 1)
		mlx_string_put(f->mlx.ptr, f->mlx.win, JUL_X - 20, JUL_Y,
				GREY, ">       <");
	mlx_string_put(f->mlx.ptr, f->mlx.win, JUL_X, JUL_Y, GREY, "Julia");
	if (f->flags.fr.ship == 1)
		mlx_string_put(f->mlx.ptr, f->mlx.win, SHIP_X - 20, SHIP_Y,
				GREY, ">      <");
	mlx_string_put(f->mlx.ptr, f->mlx.win, SHIP_X, SHIP_Y, GREY, "Ship");
	if (f->flags.fr.hugulus == 1)
		mlx_string_put(f->mlx.ptr, f->mlx.win, HUGU_X - 20, HUGU_Y,
				GREY, ">         <");
	mlx_string_put(f->mlx.ptr, f->mlx.win, HUGU_X, HUGU_Y, GREY, "Hugulus");
	mlx_string_put(f->mlx.ptr, f->mlx.win, 25, 25, GREY, "exit : ESC");
}

static void		destroy_choice(t_choice *choice, t_f *f)
{
	mlx_clear_window(f->mlx.ptr, f->mlx.win);
	mlx_destroy_image(f->mlx.ptr, choice->img.ptr);
	mlx_destroy_image(f->mlx.ptr, choice->img_xpm.ptr);
}

void			display_choice(t_f *f, int repaint)
{
	static t_choice		c;

	if (repaint == NEW)
	{
		c.img_xpm.ptr = mlx_xpm_file_to_image(f->mlx.ptr, IMG, &c.h, &c.w);
		c.img.ptr = mlx_new_image(f->mlx.ptr, 1, 700);
		c.img.data = (int*)mlx_get_data_addr(c.img.ptr,
				&c.img.bpp, &c.img.lsize, &c.img.endian);
		fill_image(c.img.data, 1, 700, GREY);
	}
	if (repaint == REPAINT || repaint == NEW)
	{
		mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, c.img_xpm.ptr, 0, 0);
		mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, c.img.ptr,
				X_WIN / 4, Y_WIN / 4);
		mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, c.img.ptr,
			2 * X_WIN / 4, Y_WIN / 4);
		mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, c.img.ptr,
			3 * X_WIN / 4, Y_WIN / 4);
		put_choice(f);
	}
	if (repaint == DESTROY)
		destroy_choice(&c, f);
	f->flags.display_repaint = 1;
}
