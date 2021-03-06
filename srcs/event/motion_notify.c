/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_notify.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 03:53:48 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/10 02:38:09 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

int				motion_notify(int x, int y, t_f *f)
{
	if (f->fract == VOID)
		motion_choice(x, y, f);
	else if (f->fract == JULIA)
		motion_julia(x, y, f);
	return (0);
}
