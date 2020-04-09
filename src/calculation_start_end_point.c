/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_rayon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 14:56:23 by xinwang           #+#    #+#             */
/*   Updated: 2020/04/09 12:15:57 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	reset_rayon_var(t_map *rVar, int x)
{
	rVar->cameraX = 2 * x / (double)WIDTH - 1;
	rVar->rayDirX = rVar->dirX + (rVar->planeX) * (rVar->cameraX);
	rVar->rayDirY = rVar->dirY + (rVar->planeY) * (rVar->cameraX);
	rVar->mapX = (int)(rVar->posX);
	rVar->mapY = (int)(rVar->posY);
	rVar->deltaDistX = sqrt(1 + (rVar->rayDirY * rVar->rayDirY) / (rVar->rayDirX * rVar->rayDirX));
	rVar->deltaDistY = sqrt(1 + (rVar->rayDirX * rVar->rayDirX) / (rVar->rayDirY * rVar->rayDirY));
	rVar->hit = 0;
}

void	calculate_side_dist(t_map	*rVar)
{
  if (rVar->rayDirX < 0)
    {
      rVar->stepX = -1;
      rVar->sideDistX = (rVar->posX - rVar->mapX) * (rVar->deltaDistX);
    }
  else
    {
      rVar->stepX = 1;
      rVar->sideDistX = (rVar->mapX + 1.0 - rVar->posX) * (rVar->deltaDistX);
    }
  if (rVar->rayDirY < 0)
    {
      rVar->stepY = -1;
      rVar->sideDistY = (rVar->posY - rVar->mapY) * (rVar->deltaDistY);
    }
  else
    {
      rVar->stepY = 1;
      rVar->sideDistY = (rVar->mapY + 1.0 - rVar->posY) * (rVar->deltaDistY);
    }
}

void	find_hits(t_map *rVar, int x)
{
	while (rVar->hit == 0)
    {
		if (rVar->sideDistX < rVar->sideDistY)
		{
			rVar->sideDistX = rVar->sideDistX + rVar->deltaDistX;
			rVar->mapX = rVar->mapX + rVar->stepX;
			rVar->side = 0;
		}
		else
		{
			rVar->sideDistY = rVar->sideDistY + rVar->deltaDistY;
			rVar->mapY = rVar->mapY + rVar->stepY;
			rVar->side = 1;
		}
		if(rVar->map[rVar->mapX][rVar->mapY] == 1)
			rVar->hit = 1;
		else if ((rVar->map[rVar->mapX][rVar->mapY] == 7 ||
				  rVar->map[rVar->mapX][rVar->mapY] == 2) &&
				 x >= WIDTH /2 - 15 && x <= WIDTH /2 + 15)
		{
			rVar->enemy.hit = 1;
			rVar->enemy.x = rVar->mapX;
			rVar->enemy.y = rVar->mapY;
		}
    }
}

void	calculate_start_end_point(t_map *rVar)
{
  if (rVar->side == 0)
    rVar->perpWallDist = (rVar->mapX - rVar->posX + (1 - rVar->stepX) / 2) / rVar->rayDirX;
  else
    rVar->perpWallDist = (rVar->mapY - rVar->posY + (1 - rVar->stepY) / 2) / rVar->rayDirY;
  rVar->lineHeight = (int)(HEIGHT / rVar->perpWallDist);
  rVar->drawStart = ((rVar->lineHeight) * -1) / 2 + HEIGHT / 2;
  if(rVar->drawStart < 0)
    rVar->drawStart = 0;
  rVar->drawEnd = rVar->lineHeight / 2 + HEIGHT / 2;
  if(rVar->drawEnd >= HEIGHT)
    rVar->drawEnd = HEIGHT - 1;
}

int get_wall_texture(t_map *rVar)
{
	if (rVar->side == 1 && rVar->rayDirY > 0)
		return (0);
    else if (rVar->side == 1 && rVar->rayDirY < 0)
		return (1);
    else if (rVar->side == 0 && rVar->rayDirX > 0)
		return (2);
    else
		return (3);
}
