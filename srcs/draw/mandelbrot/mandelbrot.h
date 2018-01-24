/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 01:36:39 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/24 06:36:53 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDELBROT_H
# define MANDELBROT_H
# include "../../../includes/fract.h"

typedef struct		s_mandel
{
	double			x1;
	double			y1;
	double			x2;
	double			y2;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			zx;
	double			zy;
	int				image_x;
	int				image_y;
	int				ite_max;
	struct s_img	img;
}					t_mandel;

#endif
