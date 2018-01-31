/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 21:35:40 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/31 01:01:45 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# include "../libft/includes/libft.h" //retirer les .. PARTOUT !!!//
# include "../minilibx_macos/mlx.h"
# include "mlx_win.h"

/*
** int value for each fractal
*/
# define MANDEL 1
# define JULIA 2

/*
** define draw
*/
# define NEW 0
# define REPAINT 1
# define DESTROY 2

/*
** Event's structs
*/
typedef struct			s_mouse
{
	double				zoom;
	double				x;
	double				y;
}						t_mouse;

typedef struct			s_key
{
	double				tr_h;
	double				tr_v;
}						t_key;

typedef struct			s_event
{
	struct s_mouse		mouse;
	struct s_key		key;
}						t_event;

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
	int					mandel_repaint;
	struct s_fr			fr;
}						t_flags;

/*
** main struct
*/
typedef struct			s_f
{
	int					fract;
	struct s_mlx		mlx;
	struct s_flags		flags;
	struct s_event		event;
	int					do_nothing;
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
int					key_mandel(int keycode, t_f *f);
int					mouse_mandel(int button, int x, int y, t_f *f);

/*
** draw foncts
*/
void				draw_mandelbrot(t_f *f, int destroy);
void				display_choice(t_f *f, int repaint);
void				draw_map(t_f *f, int fract); //mauvaise place ou nom je pense//

/*
** exit fonct
*/
void				destroy_fract(t_f *f);

/*
** reset fonct
*/
void				set_var(t_f *f);

/*
** fps fonct
*/
void				fps(t_f *f);
#endif
