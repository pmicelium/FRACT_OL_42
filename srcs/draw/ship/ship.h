/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 19:26:48 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/01 19:26:50 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHIP_H
# define SHIP_H
# include "../../../includes/fract.h"

typedef struct		s_ship
{
	int				init;
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

#endif
