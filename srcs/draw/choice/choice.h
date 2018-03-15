/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 05:19:45 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/15 00:26:09 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHOICE_H
# define CHOICE_H
# include "fract.h"

/*
** image's define
*/
# define IMG "./images/choose_fractal.xpm"

/*
** Possiton of the choice
*/
# define CROSS_Y (Y_WIN / 4 + 230)
# define MAN_X (X_WIN / 4)
# define MAN_Y (CROSS_Y - 100)
# define JUL_X ( 3 * X_WIN / 4 - 50)
# define JUL_Y (CROSS_Y - 100)
# define SHIP_X (MAN_X + 25)
# define SHIP_Y (CROSS_Y + 100)
# define HUGU_X (JUL_X)
# define HUGU_Y (CROSS_Y + 100)

typedef struct		s_choice
{
	int				h;
	int				w;
	t_img			img_xpm;
	t_img			img;
}					t_choice;

void				create_image(t_choice *c, t_f *f);
#endif
