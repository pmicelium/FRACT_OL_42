/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_cross.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 06:48:09 by pmiceli           #+#    #+#             */
/*   Updated: 2018/02/20 06:50:15 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_perso.h"

void		display_cross(t_mlx mlx)
{
	int		x;
	int		y;

	y = 0;
	x = X_WIN / 2;
	while (y < Y_WIN)
	{
		mlx_pixel_put(mlx.ptr, mlx.win, x, y, 0xFFFF00);
		y++;
	}
	y = Y_WIN / 2;
	x = 0;
	while (x < X_WIN)
	{
		mlx_pixel_put(mlx.ptr, mlx.win, x, y, 0xFFFF00);
		x++;
	}
}
