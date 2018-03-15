/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_choice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 05:19:35 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/15 00:25:21 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "choice.h"

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
	mlx_string_put(f->mlx.ptr, f->mlx.win, 25, 25, GREY, "help : H");
}

static void		destroy_choice(t_choice *choice, t_f *f)
{
	mlx_clear_window(f->mlx.ptr, f->mlx.win);
	mlx_destroy_image(f->mlx.ptr, choice->img.ptr);
	mlx_destroy_image(f->mlx.ptr, choice->img_xpm.ptr);
}

static void		draw_middle(t_f *f)
{
	static t_bresenham	b;
	static t_img		img;
	static int			init = 0;

	if (init == 0)
	{
		img.ptr = mlx_new_image(f->mlx.ptr, X_WIN, Y_WIN);
		img.data = (int *)mlx_get_data_addr(img.ptr, &img.bpp, &img.lsize,
				&img.endian);
		b.x0 = 125;
		b.y0 = Y_WIN / 4 + 230;
		b.x1 = X_WIN - 120;
		b.y1 = b.y0;
		b.color = GREY;
		b.x_win = X_WIN;
		b.y_win = Y_WIN;
		bresenham_line_mlx(b, img);
		init = 1;
	}
	mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, img.ptr, 0, 0);
}

void			display_choice(t_f *f, int repaint)
{
	static t_choice		c;

	if (repaint == NEW)
		create_image(&c, f);
	if (repaint == REPAINT || repaint == NEW)
	{
		draw_middle(f);
		mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, c.img_xpm.ptr, 0, 0);
		mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, c.img.ptr,
				2 * X_WIN / 4, Y_WIN / 4);
		put_choice(f);
	}
	if (repaint == DESTROY)
		destroy_choice(&c, f);
	f->flags.display_repaint = 1;
}
