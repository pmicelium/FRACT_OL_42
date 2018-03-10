/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 20:10:17 by pmiceli           #+#    #+#             */
/*   Updated: 2018/03/10 23:41:52 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

# include "../../../includes/fract.h"

typedef struct			s_tree
{
	int					init;
	int					x1;
	int					x2;
	int					y1;
	int					y2;
	double				angle;
	unsigned long		depth;
	t_img				img;
}						t_tree;

#endif
