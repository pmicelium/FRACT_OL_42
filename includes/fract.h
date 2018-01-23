/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 21:35:40 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/23 05:30:44 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include "mlx_win.h"

/*
** structs which contain booleans var
*/
typedef struct			s_fr
{
	int					mandel;
	int					julia;
}						t_fr;

typedef struct			s_flags
{
	int					leaks;
	int					map;
	int					display_repaint;
	struct s_fr			fr;
}						t_flags;

/*
** main struct
*/
typedef struct			s_f
{
	struct s_mlx		mlx;
	struct s_flags		flags;
	int					fract;
}						t_f;

/*
** FONCTIONS
*/

/*
** event foncts
*/
int					key_fonct(int keycode, t_f *f);
int					loop_hook(t_f *f);
int					motion_notify(int x, int y, t_f *f);
int					motion_choice(int x, int y, t_f *f);
int					mouse_fonct(int button, int x, int y, t_f *f);
int					mouse_choice(int button, int x, int y, t_f *f);

/*
** draw foncts
*/
void				display_choice(t_f *f, int repaint);
#endif
