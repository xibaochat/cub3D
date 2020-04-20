/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_rayon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 14:56:23 by xinwang           #+#    #+#             */
/*   Updated: 2020/04/20 14:35:09 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	reset_rayon_var(t_map *rvar, int x)
{
	double	r;
	double	r1;

	r = (rvar->ray_dir_y * rvar->ray_dir_y) / (rvar->ray_dir_x * rvar->ray_dir_x);
	r1 = (rvar->ray_dir_x * rvar->ray_dir_x) / (rvar->ray_dir_y * rvar->ray_dir_y);
	rvar->camera_x = 2 * x / (double)rvar->width - 1;
	rvar->ray_dir_x = rvar->dir_x + (rvar->plane_x) * (rvar->camera_x);
	rvar->ray_dir_y = rvar->dir_y + (rvar->plane_y) * (rvar->camera_x);
	rvar->map_x = (int)(rvar->pos_x);
	rvar->map_y = (int)(rvar->pos_y);
	rvar->delta_dist_x = sqrt(1 + r);
	rvar->delta_dist_y = sqrt(1 + r1);
	rvar->hit = 0;
}

void	calculate_side_dist(t_map *rvar)
{
	if (rvar->ray_dir_x < 0)
	{
		rvar->step_x = -1;
		rvar->side_dist_x = (rvar->pos_x - rvar->map_x) * (rvar->delta_dist_x);
	}
	else
	{
		rvar->step_x = 1;
		rvar->side_dist_x = (rvar->map_x + 1.0 - rvar->pos_x) * (rvar->delta_dist_x);
	}
	if (rvar->ray_dir_y < 0)
	{
		rvar->step_y = -1;
		rvar->side_dist_y = (rvar->pos_y - rvar->map_y) * (rvar->delta_dist_y);
	}
	else
	{
		rvar->step_y = 1;
		rvar->side_dist_y = (rvar->map_y + 1.0 - rvar->pos_y) * (rvar->delta_dist_y);
	}
}

void	find_hits(t_map *rvar, int x)
{
	while (rvar->hit == 0)
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
		else if ((rvar->map[rvar->map_x][rvar->map_y] == 7 ||
					rvar->map[rvar->map_x][rvar->map_y] == 2) &&
					x >= rvar->width / 2 - 15 && x <= rvar->width / 2 + 15)
		{
			rvar->enemy.hit = 1;
			rvar->enemy.x = rvar->map_x;
			rvar->enemy.y = rvar->map_y;
		}
	}
}

void	calculate_start_end_point(t_map *rvar)
{
	if (rvar->side == 0)
		rvar->perp_wall_dist = (rvar->map_x - rvar->pos_x + (1 - rvar->step_x) / 2)
		/ rvar->ray_dir_x;
	else
		rvar->perp_wall_dist = (rvar->map_y - rvar->pos_y + (1 - rvar->step_y) / 2)
		/ rvar->ray_dir_y;
	rvar->line_height = (int)(rvar->height / rvar->perp_wall_dist);
	rvar->draw_start = ((rvar->line_height) * -1) / 2 + rvar->height / 2;
	if (rvar->draw_start < 0)
		rvar->draw_start = 0;
	rvar->draw_end = rvar->line_height / 2 + rvar->height / 2;
	if (rvar->draw_end >= rvar->height)
		rvar->draw_end = rvar->height - 1;
}

int		get_wall_texture(t_map *rvar)
{
	if (rvar->side == 1 && rvar->ray_dir_y > 0)
		return (0);
	else if (rvar->side == 1 && rvar->ray_dir_y < 0)
		return (1);
	else if (rvar->side == 0 && rvar->ray_dir_x > 0)
		return (2);
	else
		return (3);
}
