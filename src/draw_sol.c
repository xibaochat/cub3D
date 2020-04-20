/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 01:24:44 by xinwang           #+#    #+#             */
/*   Updated: 2020/04/20 11:22:17 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void		init_tex_raycasting(t_map *r, int y)
{
	r->rayDirX0 = r->dirX - r->planeX;
	r->rayDirY0 = r->dirY - r->planeY;
	r->rayDirX1 = r->dirX + r->planeX;
	r->rayDirY1 = r->dirY + r->planeY;
	r->p = y - r->height / 2;
	r->posZ = 0.5 * r->height;
	r->rowDistance = r->posZ / r->p;
	r->floorStepX = r->rowDistance * \
	(r->rayDirX1 - r->rayDirX0) / r->width;
	r->floorStepY = r->rowDistance * \
	(r->rayDirY1 - r->rayDirY0) / r->width;
	r->floorX = r->posX + r->rowDistance * r->rayDirX0;
	r->floorY = r->posY + r->rowDistance * r->rayDirY0;
}

static void		init_tex_raycasting_x_cor(t_map *r)
{
	r->cellX = (int)(r->floorX);
	r->cellY = (int)(r->floorY);
	r->tx = (int)(r->width_floor * \
	(r->floorX - r->cellX)) & (r->width_floor - 1);
	r->ty = (int)(r->height_floor * (r->floorY - r->cellY)) \
	& (r->height_floor - 1);
	r->floorX += r->floorStepX;
	r->floorY += r->floorStepY;
}

void			draw_floor(t_map *r)
{
	int				j;
	int				y;
	int				x;
	int				k;
	unsigned int	color;

	y = r->height / 2;
	j = 0;
	while (y++ < r->height - 1)
	{
		init_tex_raycasting(r, y);
		x = 0;
		while (x++ < r->width - 1)
		{
			init_tex_raycasting_x_cor(r);
			k = r->width_floor * (r->ty) * (r->floor_bpp / 8) \
			+ r->tx * (r->floor_bpp / 8);
			j = (y * r->size_line) + (x * (r->bpp / 8));
			replace_pixel_value_floor(r, r->floor_texture, j, k);
		}
	}
}
