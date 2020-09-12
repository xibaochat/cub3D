/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 09:46:33 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 19:01:14 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_walls(t_map *rvar)
{
	int	x;

	x = -1;
	while (++x < rvar->width)
	{
		reset_rayon_var(rvar, x);
		calculate_side_dist(rvar);
		find_hits(rvar, x);
		calculate_start_end_point(rvar);
		draw_ceil(x, rvar);
		put_pixel(x, rvar);
		if (rvar->f_has_color && !rvar->f)
			draw_floor_if_number(x, rvar);
		rvar->spr_buffer[x] = rvar->perp_wall_dist;
	}
}
