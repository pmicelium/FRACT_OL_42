/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 00:32:53 by pmiceli           #+#    #+#             */
/*   Updated: 2018/02/20 00:32:53 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_perso.h"

int			check_draw(int x, int y, int x_img, int y_img)
{
	if ((y * x_img + x) < x_img * y_img
			&& y > 0 && x > 0
			&& y < y_img && x < x_img)
		return (CHECK_OK);
	return (CHECK_KO);
}
