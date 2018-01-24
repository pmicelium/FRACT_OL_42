/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_win.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 22:48:52 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/24 04:13:51 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_WIN_H
# define MLX_WIN_H
# define X_WIN 270 * 6
# define Y_WIN 240 * 6

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define RED 0x00FF0000
# define GREY 0x00c1c1c1
# define BLUE 0x000000FF
# define WHITE 0x00FFFFFF
# define GREEN 0x0000FF00
# define BLACK 0x00000000

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

#endif
