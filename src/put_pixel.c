/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:02:48 by xinwang           #+#    #+#             */
/*   Updated: 2020/04/18 10:53:04 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void get_tex_x(t_map	*rvar, int texNum)
{
	double wallX;

	if (rvar->side == 0)
		wallX = rvar->posY + rvar->perpWallDist * rvar->rayDirY;
	else
		wallX = rvar->posX + rvar->perpWallDist * rvar->rayDirX;
	wallX -= floor((wallX));
	rvar->tex_x = (int)(wallX * (double)(rvar->textures[texNum].w));
	if (rvar->side == 0 && rvar->rayDirX > 0)
		rvar->tex_x = rvar->textures[texNum].w - rvar->tex_x - 1;
	if (rvar->side == 1 && rvar->rayDirY < 0)
		rvar->tex_x = rvar->textures[texNum].w - rvar->tex_x - 1;
}

static void calculate_index_in_img(t_map *rvar, int x, int i, int texNum)
{

	rvar->tex_y = (int)rvar->tex_pos & (rvar->textures[texNum].h - 1);
	rvar->tex_pos += rvar->step;
}

void replace_pixel_value_floor(t_map *rvar, char *s2, int j, int k)
{
	if (rvar->endian == 0)
	{
		rvar->addr[j] = s2[k];
		rvar->addr[j + 1] = s2[k + 1];
		rvar->addr[j + 2] = s2[k + 2];
	}
	else
	{
		rvar->addr[j] = s2[k + 2];
		rvar->addr[j + 1] = s2[k + 1];
		rvar->addr[j + 2] = s2[k];
	}
}

void change_char_in_addr_value(t_map *rvar, char *s2, int j, int k)
{
	int color;

	color = *(int *)(s2 + k);
	if (rvar->side)
		color = (color >> 1) & 8355711;
	if (rvar->endian == 0)
    {
		rvar->addr[j] = color;
		rvar->addr[j + 1] = color >> 8;
		rvar->addr[j + 2] = color >> 16;
	}
	else
    {
		rvar->addr[j] = color >> 16;
		rvar->addr[j + 1] = color >> 8;
		rvar->addr[j + 2] = color;
	}
}

void put_pixel(int x, t_map *rvar)
{
	int   i;
	int   j;
	int k;
	int texNum;

	texNum = get_wall_texture(rvar);
	i = rvar->drawStart;
	rvar->step = 1.0 * (rvar->textures[texNum].h) / rvar->lineHeight;
	rvar->tex_pos = (rvar->drawStart - HEIGHT / 2 + rvar->lineHeight / 2) * rvar->step;
	get_tex_x(rvar, texNum);
	while (i++ < rvar->drawEnd)
	{
		calculate_index_in_img(rvar, x, i, texNum);
		k = (rvar->tex_y * rvar->s_l + rvar->tex_x * (rvar->bpp / 8));
		j = (i * rvar->size_line) + (x * (rvar->bpp) / 8);
		change_char_in_addr_value(rvar, rvar->textures[texNum].addr, j, k);
	}
}
