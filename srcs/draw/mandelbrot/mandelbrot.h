/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 01:36:39 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/15 18:20:26 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDELBROT_H
# define MANDELBROT_H
# include "fract.h"

# define RATIO_V 1.0 / 20.0 * (m->y2 - m->y1)
# define RATIO_H 1.0 / 20.0 * (m->x2 - m->x1)

typedef struct		s_mandel
{
	int				init;
	int				color;
	double			x1;
	double			y1;
	double			x2;
	double			y2;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			zoom_x;
	double			zoom_y;
	double			k;
	double			fx;
	double			fy;
	long			ite_max;
	struct s_img	img;
}					t_mandel;

void				mandel_key(t_mandel *m, t_f *f);

#endif
