/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_win.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 22:48:52 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/30 04:19:12 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_WIN_H
# define MLX_WIN_H
# define X_WIN 1793
# define Y_WIN 1272

/*
** Key's defines
*/
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define MOUSE_ONE 1
# define MOUSE_TWO 2
# define WHEEL_UP 4
# define WHEEL_DW 5

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
** check if you can draw at (x, y) in a image of size (x_img, y_img)
** return CHECK_OK = 1 if it's good, CHECK_KO = 0if it isnt
*/
int					check_draw(int x, int y, int x_img, int y_img);
#endif
