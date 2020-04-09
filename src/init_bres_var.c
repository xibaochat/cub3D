/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bres_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:05:45 by xinwang           #+#    #+#             */
/*   Updated: 2020/02/18 21:37:36 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_bres	init_bres(int x1, int x2, int y1, int y2)
{
	t_bres bres_var;

	bres_var.x = x1;
	bres_var.y = y1;
	bres_var.dx = abs(x2 - x1);
	bres_var.dy = abs(y2 - y1);
	bres_var.s1 = sign(x2 - x1);
	bres_var.s2 = sign(y2 - y1);
	bres_var.is_swap = 0;

	if (bres_var.dy > bres_var.dx)
		swap_distance(&bres_var);
	bres_var.D = (2 * bres_var.dy) - bres_var.dx;
	return (bres_var);
}
