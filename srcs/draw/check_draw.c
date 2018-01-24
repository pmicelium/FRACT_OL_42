/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 05:41:07 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/24 05:49:30 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_win.h"

int			check_draw(int x, int y, int x_img, int y_img)
{
	if ((y * x_img + x) < x_img * y_img
			&& y > 0 && x > 0
			&& y < y_img && x < x_img)
		return (CHECK_OK);
	return (CHECK_KO);
}
