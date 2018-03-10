/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 05:40:23 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/10 05:43:05 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_perso.h"

void				init_img(t_img *img, t_mlx *mlx)
{
	img->ptr = mlx_new_image(mlx->ptr, X_WIN, Y_WIN);
	img->data = (int*)mlx_get_data_addr(img->ptr, &img->bpp,
			&img->lsize, &img->endian);
}
