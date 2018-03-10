/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 20:13:38 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/11 00:38:41 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static void		init_tree(t_tree *t)
{
	t->x1 = X_WIN / 2;
	t->y1 = Y_WIN;
	t->angle = -5156 * M_PI / 180;
	t->depth = 9;
}

static void		draw_tree_recursive(int x1, int y1, double angle, int depth, t_img *img)
{
	t_bresenham		b;
	int				x2;
	int				y2;

	if (depth != 0)
	{
		x2 = x1 + (cos(angle * M_PI / 180) * depth * 10.00);
		y2 = y1 + (sin(angle * M_PI / 180) * depth * 10.00);
		b.x0 = x1;
		b.x1 = x2;
		b.y0 = y1;
		b.y1 = y2;
		b.x_win = X_WIN;
		b.y_win = Y_WIN;
		b.color = GREY;
		bresenham_line_mlx(b, *img);
		draw_tree_recursive(x2, y2, angle - 20, depth - 1, img);
		draw_tree_recursive(x2, y2, angle + 20, depth - 1, img);
	}
}

void			draw_tree(t_f *f, int repaint)
{
	static t_tree	t;

	if (!t.init)
		init_tree(&t);
	if (repaint == NEW)
	{
		init_img(&t.img, &f->mlx);
		draw_tree_recursive(X_WIN / 2, Y_WIN, -90, 15, &t.img);
	}
	if (repaint == NEW || repaint == REPAINT)
		mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, t.img.ptr, 0, 0);
	f->flags.tree_repaint = 1;
	if (repaint == DESTROY)
	{
		t.init = 0;
		mlx_destroy_image(f->mlx.ptr, t.img.ptr);
	}
}
