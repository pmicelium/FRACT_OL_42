/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 19:19:50 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/14 19:26:00 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract.h"

int			color(int color, int i)
{
	i += color;
	if (color < 14)
		return (2 * i + 2);
	if (color > 30 && color < 40)
		return (13 * i - 11);
	if (color > 50 && color < 60)
		return (7 * i + 1);
	if (color > 100)
		return (21 * i - 9);
	return (19 * i - 5);
}
