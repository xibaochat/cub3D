/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_rayon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 14:56:23 by xinwang           #+#    #+#             */
/*   Updated: 2020/04/20 18:34:19 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	reset_rayon_var(t_map *r, int x)
{
	double	r0;
	double	r1;

	r0 = (r->ray_dir_y * r->ray_dir_y) / (r->ray_dir_x * r->ray_dir_x);
	r1 = (r->ray_dir_x * r->ray_dir_x) / (r->ray_dir_y * r->ray_dir_y);
	r->camera_x = 2 * x / (double)r->width - 1;
	r->ray_dir_x = r->dir_x + (r->plane_x) * (r->camera_x);
	r->ray_dir_y = r->dir_y + (r->plane_y) * (r->camera_x);
	r->map_x = (int)(r->pos_x);
	r->map_y = (int)(r->pos_y);
	r->delta_dist_x = sqrt(1 + r0);
	r->delta_dist_y = sqrt(1 + r1);
	r->hit = 0;
}

void	calculate_side_dist(t_map *r)
{
	if (r->ray_dir_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (r->pos_x - r->map_x) * (r->delta_dist_x);
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = (r->map_x + 1.0 - r->pos_x) * (r->delta_dist_x);
	}
	if (r->ray_dir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (r->pos_y - r->map_y) * (r->delta_dist_y);
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = (r->map_y + 1.0 - r->pos_y) * (r->delta_dist_y);
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

void	calculate_start_end_point(t_map *rv)
{
	if (rv->side == 0)
		rv->perp_wall_dist = (rv->map_x - rv->pos_x + (1 - rv->step_x) / 2)
		/ rv->ray_dir_x;
	else
		rv->perp_wall_dist = (rv->map_y - rv->pos_y + (1 - rv->step_y) / 2)
		/ rv->ray_dir_y;
	rv->line_height = (int)(rv->height / rv->perp_wall_dist);
	rv->draw_start = ((rv->line_height) * -1) / 2 + rv->height / 2;
	if (rv->draw_start < 0)
		rv->draw_start = 0;
	rv->draw_end = rv->line_height / 2 + rv->height / 2;
	if (rv->draw_end >= rv->height)
		rv->draw_end = rv->height - 1;
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
