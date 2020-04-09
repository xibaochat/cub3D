/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:38:40 by xinwang           #+#    #+#             */
/*   Updated: 2020/02/19 16:35:07 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void draw_line(void *mlx_ptr, void *win_ptr, int x1, int x2, int y1, int y2, int distance)
{
	t_bres	bres_var;
	int		i;
	int color = 0xFFFFFF;

	bres_var =  init_bres(x1, x2, y1, y2);
	i = 0;
	while (i < bres_var.dx)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, bres_var.x,  bres_var.y +  distance, color);
		while (bres_var.D >= 0)
		{
			bres_var.D -= (2 * bres_var.dx);
			if (bres_var.is_swap)
				bres_var.x += bres_var.s1;
			else
				bres_var.y += bres_var.s2;
		}
		bres_var.D = bres_var.D + (2 * bres_var.dy);
		if (bres_var.is_swap)
			bres_var.y += bres_var.s2;
		else
			bres_var.x += bres_var.s1;
		++i;
	}
}
