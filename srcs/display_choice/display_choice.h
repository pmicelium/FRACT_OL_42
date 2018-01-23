/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_choice.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 02:23:31 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/23 05:03:34 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_CHOICE_H
# define DISPLAY_CHOICE_H
# include "../../includes/mlx_win.h"
# include "../../includes/fract.h"

/*
** Possiton of the choice
*/
# define MAN_X (X_WIN / 6 - 25)
# define MAN_Y (Y_WIN / 3 + 50)
# define JUL_X (3 * X_WIN / 6 - 15)
# define JUL_Y (Y_WIN / 3 + 50)

/*
** value for selection
*/
# define MANDEL 1
# define JULIA 2

typedef struct		s_choice
{
	int				h;
	int				w;
	struct s_img	img_xpm;
	struct s_img	img;
}					t_choice;

#endif
