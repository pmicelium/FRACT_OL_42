/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:41:04 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/15 18:27:54 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JULIA_H
# define JULIA_H
# include "fract.h"

# define RATIO_V 1.0 / 20.0 * (j->y2 - j->y1)
# define RATIO_H 1.0 / 20.0 * (j->x2 - j->x1)

typedef struct		s_julia
{
	int				init;
	int				init2;
	int				x;
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
}					t_julia;

void				julia_key(t_julia *j, t_f *f);
void				change_c(t_julia *j, t_f *f);
void				zoom_julia(t_julia *j, t_f *f);
#endif
