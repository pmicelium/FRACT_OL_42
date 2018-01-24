/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 05:19:45 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/24 05:05:37 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHOICE_H
# define CHOICE_H
# include "mlx_win.h"
# include "fract.h"

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
