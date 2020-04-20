/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_enemy_to_damage.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 10:20:32 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 10:21:45 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		find_enemy(t_map *rvar)
{
	int	enemy_hit;

	enemy_hit = 0;
	while (enemy_hit == 0)
	{
		if (rvar->side_dist_x < rvar->side_dist_y)
		{
			rvar->side_dist_x = rvar->side_dist_x + rvar->delta_dist_x;
			rvar->map_x = rvar->map_x + rvar->step_x;
			rvar->side = 0;
		}
		else
		{
			rvar->side_dist_y = rvar->side_dist_y + rvar->delta_dist_y;
			rvar->map_y = rvar->map_y + rvar->step_y;
			rvar->side = 1;
		}
		if (rvar->map[rvar->map_x][rvar->map_y] == 1)
			rvar->hit = 1;
	}
}

t_spr	*detect_enemy_to_damage(t_map *rvar)
{
	int x;

	x = -1;
	while (++x < rvar->width)
	{
		reset_rayon_var(rvar, x);
		calculate_side_dist(rvar);
		find_wall(rvar);
	}
}
