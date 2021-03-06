/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hugulus.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 01:34:37 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/15 18:32:53 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUGULUS_H
# define HUGULUS_H
# include "fract.h"

# define RATIO_V 1.0 / 20.0 * (h->y2 - h->y1)
# define RATIO_H 1.0 / 20.0 * (h->x2 - h->x1)

typedef struct		s_hugulus
{
	int				init;
	int				init2;
	int				color;
	double			x1;
	double			x2;
	double			y1;
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
	unsigned long	ite_max;
	struct s_img	img;
}					t_hugulus;

void				hugulus_key(t_hugulus *h, t_f *f);
#endif
