/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 21:48:28 by pmiceli           #+#    #+#             */
/*   Updated: 2018/02/06 04:01:47 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static int		check_for_fract(int argc, char *argv[], t_f *f)
{
	if (argc == 1)
		return (0);
	if (argc > 2)
		return (2);
	f->flags.map = 0;
	if (ft_strcmp(argv[1], "Mandelbrot") == 0)
	{
		f->flags.map = 1;
		f->fract = MANDEL;
		return (1);
	}
	else if (ft_strcmp(argv[1], "Julia") == 0)
	{
		f->flags.map = 1;
		f->fract = JULIA;
		return (1);
	}
	return (2);
}

void			set_var(t_f *f)
{
	f->fract = 0;
	f->flags.map = 0;
	f->flags.leaks = 0;
	f->flags.display_repaint = 0;
	f->flags.mandel_repaint = 0;
	f->flags.fr.mandel = 0;
	f->flags.fr.julia = 0;
	f->event.mouse.zoom = 0.78;
	f->event.mouse.x = X_WIN / 2;
	f->event.mouse.y = Y_WIN / 2;
	f->event.motion.x = 0;
	f->event.motion.y = 0;
	f->event.key.tr_h = 0;
	f->event.key.tr_v = 0;
	f->event.key.nb_ite = 3;
}

int				main(int argc, char *argv[])
{
	t_f		f;

	set_var(&f);
	if (check_for_fract(argc, argv, &f) == 2)
		ft_putendl_color("bad argument", "red");
	f.mlx.ptr = mlx_init();
	f.mlx.win = mlx_new_window(f.mlx.ptr, X_WIN, Y_WIN, "FRACT'OL 42");
	mlx_hook(f.mlx.win, 2, (1l << 8), &key_fonct, &f);
	mlx_hook(f.mlx.win, 4, (1l << 8), &mouse_fonct, &f);
	mlx_hook(f.mlx.win, 6, (1L << 13), &motion_notify, &f);
	mlx_loop_hook(f.mlx.ptr, loop_hook, &f);
	mlx_loop(f.mlx.ptr);
	return (0);
}
