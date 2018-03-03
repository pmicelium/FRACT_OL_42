/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_line_mlx.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 18:27:10 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/03 19:11:20 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_perso.h"

void			bresenham_line_mlx(t_bresenham b, t_img img)
{
	b.dx = ft_abs(b.x1 - b.x0);
	b.dy = -ft_abs(b.y1 - b.y0);
	b.inc_x = b.x0 < b.x1 ? 1 : -1;
	b.inc_y = b.y0 < b.y1 ? 1 : -1;
	b.e = b.dx + b.dy;
	while (1)
	{
		if (check_draw(b.x0, b.y0, b.x_win, b.y_win) == CHECK_OK)
			img.data[b.y0 * b.x_win + b.x0] = b.color;
		if (b.x0 == b.x1 && b.y0 == b.y1)
			break ;
		b.e2 = b.e * 2;
		if (b.e2 >= b.dy)
		{
			b.e += b.dy;
			b.x0 += b.inc_x;
		}
		if (b.e2 <= b.dx)
		{
			b.e += b.dx;
			b.y0 += b.inc_y;
		}
	}
}
