/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 21:35:40 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/15 00:10:18 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H
# include "../lib/libft/includes/libft.h"
# include "../lib/minilibx_macos/mlx.h"
# include "../lib/mlx_perso/includes/mlx_perso.h"

# define HELP_IMG "./images/help.xpm"

/*
** int value for each fractal
*/
# define VOID 0
# define MANDEL 1
# define JULIA 2
# define SHIP 3
# define HUGULUS 5

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
	int					flag;
	double				zoom;
	double				x;
	double				y;
}						t_mouse;

typedef struct			s_key
{
	int					flag;
	double				tr_h;
	double				tr_v;
	long				ite;
}						t_key;

typedef struct			s_motion
{
	int					flag;
	double				x;
	double				y;
}						t_motion;

typedef struct			s_event
{
	t_mouse				mouse;
	t_key				key;
	t_motion			motion;
}						t_event;

/*
** structs which contain booleans var
*/
typedef struct			s_fr
{
	int					voidd;
	int					mandel;
	int					julia;
	int					ship;
	int					hugulus;
}						t_fr;

typedef struct			s_flags
{
	int					display_repaint;
	int					mandel_repaint;
	int					julia_repaint;
	int					ship_repaint;
	int					hugulus_repaint;
	t_fr				fr;
}						t_flags;

/*
** help strcut
*/
typedef struct			s_help
{
	t_img				img;
	int					flag;
	int					w;
	int					h;
}						t_help;

/*
** main struct
*/
typedef struct			s_f
{
	int					fract;
	int					color;
	t_mlx				mlx;
	t_flags				flags;
	t_event				event;
	t_help				help;
}						t_f;

/*
** FONCTIONS
*/

/*
** event foncts
*/
int						key_fonct(int keycode, t_f *f);
int						loop_hook(t_f *f);

int						motion_notify(int x, int y, t_f *f);
int						motion_choice(int x, int y, t_f *f);
int						motion_julia(int x, int y, t_f *f);

int						mouse_fonct(int button, int x, int y, t_f *f);
int						mouse_choice(int button, int x, int y, t_f *f);
int						mouse_mandel(int button, int x, int y, t_f *f);
int						mouse_julia(int button, int x, int y, t_f *f);
int						mouse_ship(int button, int x, int y, t_f *f);
int						mouse_hugulus(int button, int x, int y, t_f *f);

int						key_mandel(int keycode, t_f *f);
int						key_julia(int keycode, t_f *f);
int						key_hugulus(int keycode, t_f *f);
int						key_ship(int keycode, t_f *f);

/*
** draw foncts
*/
void					draw_mandelbrot(t_f *f, int repaint);
void					draw_julia(t_f *f, int repaint);
void					draw_ship(t_f *f, int repaint);
void					draw_hugulus(t_f *f, int repaint);
void					display_choice(t_f *f, int repaint);
void					draw_map(t_f *f, int fract);

/*
** exit fonct
*/
void					destroy_fract(t_f *f);

/*
** reset fonct
*/
void					set_var(t_f *f);

/*
** fps fonct
*/
void					fps(t_f *f);

#endif
