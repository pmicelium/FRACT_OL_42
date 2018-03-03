/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 20:13:38 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/03 20:24:46 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static void		init_tree(t_tree *t, t_f *f)
{
	t->x1 = X_WIN / 2;
	t->y1 = Y_WIN;
	t->angle = 90.0 * M_PI / 180;
	t->depth = f->event.key.ite;
}

void			draw_tree(t_f *f, int repaint)
{
	static t_tree	t;

	if (!t.init)
		init_tree(&t, f);
}
