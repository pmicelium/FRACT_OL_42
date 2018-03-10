/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 00:51:45 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/10 03:37:46 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int						loop_hook(t_f *f)
{
	mlx_clear_window(f->mlx.ptr, f->mlx.win);
//	if (f->fract == VOID)
//		draw_map(f, VOID);
//	else
	draw_map(f, f->fract);
	fps(f);
	return (0);
}
