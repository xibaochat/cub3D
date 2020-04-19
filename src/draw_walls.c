/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 09:46:33 by osshit            #+#    #+#             */
/*   Updated: 2020/04/18 10:50:41 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_walls(void *mlx_ptr, void *win_ptr, t_map *rvar)
{
	int	x;

	x = -1;
	while (++x < WIDTH)
	{
		reset_rayon_var(rvar, x);
		calculate_side_dist(rvar);
		find_hits(rvar, x);
		calculate_start_end_point(rvar);
		draw_ceil(x, rvar);
		put_pixel(x, rvar);
		rvar->spr_buffer[x] = rvar->perpWallDist;
	}
}
