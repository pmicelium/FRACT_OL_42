/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 05:19:45 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/12 23:02:01 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHOICE_H
# define CHOICE_H
# include "fract.h"
# define IMG "./images/choose_fractal.xpm"

/*
** Possiton of the choice
*/
# define MAN_X (X_WIN / 8 - 25)
# define MAN_Y (Y_WIN / 3 + 50)
# define JUL_X (3 * X_WIN / 8 - 15)
# define JUL_Y (Y_WIN / 3 + 50)
# define SHIP_X (5 * X_WIN / 8 - 25)
# define SHIP_Y (Y_WIN / 3 + 50)
# define HUGU_X (7 * X_WIN / 8 - 25)
# define HUGU_Y (Y_WIN / 3 + 50)

typedef struct		s_choice
{
	int				h;
	int				w;
	struct s_img	img_xpm;
	struct s_img	img;
}					t_choice;

#endif
