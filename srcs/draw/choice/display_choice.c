/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_choice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 05:19:35 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/24 04:46:23 by pmiceli          ###   ########.fr       */
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
	static t_choice		choice;

	if (repaint == NEW)
	{
		choice.img_xpm.ptr = mlx_xpm_file_to_image(f->mlx.ptr,
				"./images/choose_fractal.xpm", &choice.h, &choice.w);
		choice.img.ptr = mlx_new_image(f->mlx.ptr, 1, 700);
		choice.img.data = (int*)mlx_get_data_addr(choice.img.ptr,
				&choice.img.bpp, &choice.img.lsize, &choice.img.endian);
		fill_image(choice.img.data, 1, 700, GREY);
	}
	if (repaint == REPAINT || repaint == NEW)
	{
		mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, choice.img_xpm.ptr, 0,
				0);
		mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, choice.img.ptr,
				X_WIN / 3, Y_WIN / 3);
		mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, choice.img.ptr,
			2 * X_WIN / 3, Y_WIN / 3);
		put_choice(f);
	}
	if (repaint == DESTROY)
		destroy_choice(&choice, f);
	f->flags.display_repaint = 1;
}
