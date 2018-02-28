#ifndef JULIA_H
# define JULIA_H
#include "../../../includes/fract.h"

typedef struct		s_julia
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
	struct s_img	img;
}					t_julia;

#endif