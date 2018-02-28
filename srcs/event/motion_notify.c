/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_notify.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 03:53:48 by pmiceli           #+#    #+#             */
/*   Updated: 2018/02/28 18:18:51 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

int				motion_notify(int x, int y, t_f *f)
{
	if (f->flags.map == 0)
		motion_choice(x, y, f);
	else if(f->fract == JULIA)
		motion_julia(x, y, f);
	return (0);
}
