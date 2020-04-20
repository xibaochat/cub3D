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
		if (rvar->sideDistX < rvar->sideDistY)
		{
			rvar->sideDistX = rvar->sideDistX + rvar->deltaDistX;
			rvar->mapX = rvar->mapX + rvar->stepX;
			rvar->side = 0;
		}
		else
		{
			rvar->sideDistY = rvar->sideDistY + rvar->deltaDistY;
			rvar->mapY = rvar->mapY + rvar->stepY;
			rvar->side = 1;
		}
		if (rvar->map[rvar->mapX][rvar->mapY] == 1)
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
