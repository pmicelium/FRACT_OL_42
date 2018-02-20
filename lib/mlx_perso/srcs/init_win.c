/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 00:32:49 by pmiceli           #+#    #+#             */
/*   Updated: 2018/02/20 00:32:51 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_perso.h"

t_mlx			init_win(t_mlx mlx, char* name)
{
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, X_WIN, Y_WIN, name);
	return (mlx);
}
