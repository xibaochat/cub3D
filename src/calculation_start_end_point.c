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

	r = (rvar->rayDirY * rvar->rayDirY) / (rvar->rayDirX * rvar->rayDirX);
	r1 = (rvar->rayDirX * rvar->rayDirX) / (rvar->rayDirY * rvar->rayDirY);
	rvar->cameraX = 2 * x / (double)rvar->width - 1;
	rvar->rayDirX = rvar->dirX + (rvar->planeX) * (rvar->cameraX);
	rvar->rayDirY = rvar->dirY + (rvar->planeY) * (rvar->cameraX);
	rvar->mapX = (int)(rvar->posX);
	rvar->mapY = (int)(rvar->posY);
	rvar->deltaDistX = sqrt(1 + r);
	rvar->deltaDistY = sqrt(1 + r1);
	rvar->hit = 0;
}

void	calculate_side_dist(t_map *rvar)
{
	if (rvar->rayDirX < 0)
	{
		rvar->stepX = -1;
		rvar->sideDistX = (rvar->posX - rvar->mapX) * (rvar->deltaDistX);
	}
	else
	{
		rvar->stepX = 1;
		rvar->sideDistX = (rvar->mapX + 1.0 - rvar->posX) * (rvar->deltaDistX);
	}
	if (rvar->rayDirY < 0)
	{
		rvar->stepY = -1;
		rvar->sideDistY = (rvar->posY - rvar->mapY) * (rvar->deltaDistY);
	}
	else
	{
		rvar->stepY = 1;
		rvar->sideDistY = (rvar->mapY + 1.0 - rvar->posY) * (rvar->deltaDistY);
	}
}

void	find_hits(t_map *rvar, int x)
{
	while (rvar->hit == 0)
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
		else if ((rvar->map[rvar->mapX][rvar->mapY] == 7 ||
					rvar->map[rvar->mapX][rvar->mapY] == 2) &&
					x >= rvar->width / 2 - 15 && x <= rvar->width / 2 + 15)
		{
			rvar->enemy.hit = 1;
			rvar->enemy.x = rvar->mapX;
			rvar->enemy.y = rvar->mapY;
		}
	}
}

void	calculate_start_end_point(t_map *rvar)
{
	if (rvar->side == 0)
		rvar->perpWallDist = (rvar->mapX - rvar->posX + (1 - rvar->stepX) / 2)
		/ rvar->rayDirX;
	else
		rvar->perpWallDist = (rvar->mapY - rvar->posY + (1 - rvar->stepY) / 2)
		/ rvar->rayDirY;
	rvar->lineHeight = (int)(rvar->height / rvar->perpWallDist);
	rvar->drawStart = ((rvar->lineHeight) * -1) / 2 + rvar->height / 2;
	if (rvar->drawStart < 0)
		rvar->drawStart = 0;
	rvar->drawEnd = rvar->lineHeight / 2 + rvar->height / 2;
	if (rvar->drawEnd >= rvar->height)
		rvar->drawEnd = rvar->height - 1;
}

int		get_wall_texture(t_map *rvar)
{
	if (rvar->side == 1 && rvar->rayDirY > 0)
		return (0);
	else if (rvar->side == 1 && rvar->rayDirY < 0)
		return (1);
	else if (rvar->side == 0 && rvar->rayDirX > 0)
		return (2);
	else
		return (3);
}
