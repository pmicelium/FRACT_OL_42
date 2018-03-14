/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 22:33:02 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/14 22:41:15 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "choice.h"

static void		fill_image(int *img, int x, int y, int color)
{
	int i;
	int j;

	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			img[j * x + i] = color;
			i++;
		}
		j++;
	}
}

void			create_image(t_choice *c, t_f *f)
{
	c->img_xpm.ptr = mlx_xpm_file_to_image(f->mlx.ptr, IMG, &c->h, &c->w);
	c->img.ptr = mlx_new_image(f->mlx.ptr, 1, 700);
	c->img.data = (int*)mlx_get_data_addr(c->img.ptr,
			&c->img.bpp, &c->img.lsize, &c->img.endian);
	fill_image(c->img.data, 1, 480, GREY);
}
