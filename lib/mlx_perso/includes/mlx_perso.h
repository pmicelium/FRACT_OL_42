/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_win.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 22:48:52 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/14 21:40:30 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_PERSO_H
# define MLX_PERSO_H
# include "../../minilibx_macos/mlx.h"
# include "mlx_define.h"
# include "../../libft/includes/libft.h"

/*
**# define X_WIN 1920
**# define Y_WIN 1080
*/


# define X_WIN 1080
# define Y_WIN 800


/*
** color's defines
*/
# define RED 0x00FF0000
# define GREY 0x00c1c1c1
# define BLUE 0x000000FF
# define WHITE 0x00FFFFFF
# define GREEN 0x0000FF00
# define BLACK 0x00000000

/*
** define for the check_draw fonction
*/
# define CHECK_OK 1
# define CHECK_KO 0

/*
** MLX struct
*/
typedef struct		s_img
{
	void			*ptr;
	int				*data;
	int				lsize;
	int				endian;
	int				bpp;
}					t_img;

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
	struct s_img	img;
}					t_mlx;

/*
** bresenham struct
*/
typedef struct		s_bresenham
{
	int				x0;
	int				x1;
	int				y0;
	int				y1;
	int				color;
	int				x_win;
	int				y_win;
	int				dx;
	int				dy;
	int				inc_x;
	int				inc_y;
	int				e;
	int				e2;
}					t_bresenham;

/*
** check if you can draw at (x, y) in a image of size (x_img, y_img)
** return CHECK_OK = 1 if it's good, CHECK_KO = 0if it isnt
*/
int					check_draw(int x, int y, int x_img, int y_img);

/*
** initialise an mlx img and it's mlx.data
*/
void				init_img(t_img *img, t_mlx *mlx);

/*
** make a line between b.x0, b.x1 and b.y0, b.y1
** need to initialise x0, x1, y0, y1, x_win, y_win and color in  the struct
** s_bresenham
** img need to have a img.ptr and img.data initialisated with the mlx
*/
void				bresenham_line_mlx(t_bresenham b, t_img img);

/*
** display a yellow cross on the center on he screen
*/
void				display_cross(t_mlx mlx);
#endif
