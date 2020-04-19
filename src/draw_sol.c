/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 01:24:44 by xinwang           #+#    #+#             */
/*   Updated: 2020/04/18 10:53:28 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_tex_raycasting(t_map *rvar, int y)
{
    rvar->rayDirX0 = rvar->dirX - rvar->planeX;
    rvar->rayDirY0 = rvar->dirY - rvar->planeY;
    rvar->rayDirX1 = rvar->dirX + rvar->planeX;
    rvar->rayDirY1 = rvar->dirY + rvar->planeY;
    rvar->p = y - HEIGHT / 2;
    rvar->posZ = 0.5 * HEIGHT;
    rvar->rowDistance = rvar->posZ / rvar->p;
    rvar->floorStepX = rvar->rowDistance * (rvar->rayDirX1 - rvar->rayDirX0) / WIDTH;
    rvar->floorStepY = rvar->rowDistance * (rvar->rayDirY1 - rvar->rayDirY0) / WIDTH;
    rvar->floorX = rvar->posX + rvar->rowDistance * rvar->rayDirX0;
    rvar->floorY = rvar->posY + rvar->rowDistance * rvar->rayDirY0;
}

static void	init_tex_raycasting_x_cor(t_map *rvar)
{
    rvar->cellX = (int)(rvar->floorX);
    rvar->cellY = (int)(rvar->floorY);
    rvar->tx = (int)(rvar->width_floor * (rvar->floorX - rvar->cellX)) & (rvar->width_floor - 1);
    rvar->ty = (int)(rvar->height_floor * (rvar->floorY - rvar->cellY)) & (rvar->height_floor - 1);
    rvar->floorX += rvar->floorStepX;
    rvar->floorY += rvar->floorStepY;
}

void	draw_floor(t_map *rvar)
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
        init_tex_raycasting(rvar, y);
        x = 0;
        while (x++ < WIDTH - 1)
        {
            init_tex_raycasting_x_cor(rvar);
            k = rvar->width_floor * (rvar->ty) * (rvar->floor_bpp / 8) + rvar->tx * (rvar->floor_bpp / 8);
            j = (y * rvar->size_line) + (x * (rvar->bpp/8));
			replace_pixel_value_floor(rvar, rvar->floor_texture, j, k);
        }
	}
}
