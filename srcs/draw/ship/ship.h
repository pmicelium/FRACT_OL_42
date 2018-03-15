/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 19:26:48 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/15 19:13:03 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHIP_H
# define SHIP_H
# include "fract.h"

# define RATIO_V 1.0 / 20.0 * (s->y2 - s->y1)
# define RATIO_H 1.0 / 20.0 * (s->x2 - s->x1)

typedef struct		s_ship
{
	int				init;
	int				init2;
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
	double			ite_max;
	double			k;
	double			fx;
	double			fy;
	struct s_img	img;
}					t_ship;

void				ship_key(t_ship *s, t_f *f);

#endif
