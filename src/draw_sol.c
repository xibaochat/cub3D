/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 01:24:44 by xinwang           #+#    #+#             */
/*   Updated: 2020/04/07 09:41:11 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_tex_raycasting(t_map *rVar, int y)
{
    rVar->rayDirX0 = rVar->dirX - rVar->planeX;
    rVar->rayDirY0 = rVar->dirY - rVar->planeY;
    rVar->rayDirX1 = rVar->dirX + rVar->planeX;
    rVar->rayDirY1 = rVar->dirY + rVar->planeY;
    rVar->p = y - HEIGHT / 2;
    rVar->posZ = 0.5 * HEIGHT;
    rVar->rowDistance = rVar->posZ / rVar->p;
    rVar->floorStepX = rVar->rowDistance * (rVar->rayDirX1 - rVar->rayDirX0) / WIDTH;
    rVar->floorStepY = rVar->rowDistance * (rVar->rayDirY1 - rVar->rayDirY0) / WIDTH;
    rVar->floorX = rVar->posX + rVar->rowDistance * rVar->rayDirX0;
    rVar->floorY = rVar->posY + rVar->rowDistance * rVar->rayDirY0;
}

static void	init_tex_raycasting_x_cor(t_map *rVar)
{
    rVar->cellX = (int)(rVar->floorX);
    rVar->cellY = (int)(rVar->floorY);
    rVar->tx = (int)(rVar->width_floor * (rVar->floorX - rVar->cellX)) & (rVar->width_floor - 1);
    rVar->ty = (int)(rVar->height_floor * (rVar->floorY - rVar->cellY)) & (rVar->height_floor - 1);
    rVar->floorX += rVar->floorStepX;
    rVar->floorY += rVar->floorStepY;
}

void	draw_floor(t_map *rVar)
{
    int				j;
    int				y;
    int				x;
    int				k;
    unsigned int	color;

    y = HEIGHT / 2;
    j = 0;
    while (y++ < HEIGHT - 1)
    {
        init_tex_raycasting(rVar, y);
        x = 0;
        while (x++ < WIDTH - 1)
        {
            init_tex_raycasting_x_cor(rVar);
            k = rVar->width_floor * (rVar->ty) * (rVar->floor_bpp / 8) + rVar->tx * (rVar->floor_bpp / 8);
            j = (y * rVar->size_line) + (x * (rVar->bpp/8));
			replace_pixel_value_floor(rVar, rVar->floor_texture, j, k);
        }
	}
}
