/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 00:35:23 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/24 00:46:12 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FPS_H
# define FPS_H
# include "../../includes/fract.h"
# include "../../includes/mlx_win.h"
# include <time.h>

typedef struct		s_fps
{
	unsigned int	fps;
	unsigned int	start;
}					t_fps;

void				fps(t_f*f);
#endif
