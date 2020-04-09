/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:02:48 by xinwang           #+#    #+#             */
/*   Updated: 2020/04/08 09:35:18 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void get_tex_x(t_map	*rVar, int texNum)
{
	double wallX;

	if (rVar->side == 0)
		wallX = rVar->posY + rVar->perpWallDist * rVar->rayDirY;
	else
		wallX = rVar->posX + rVar->perpWallDist * rVar->rayDirX;
	wallX -= floor((wallX));
	rVar->tex_x = (int)(wallX * (double)(rVar->textures[texNum].w));
	if (rVar->side == 0 && rVar->rayDirX > 0)
		rVar->tex_x = rVar->textures[texNum].w - rVar->tex_x - 1;
	if (rVar->side == 1 && rVar->rayDirY < 0)
		rVar->tex_x = rVar->textures[texNum].w - rVar->tex_x - 1;
}

static void calculate_index_in_img(t_map *rVar, int x, int i, int texNum)
{

	rVar->tex_y = (int)rVar->tex_pos & (rVar->textures[texNum].h - 1);
	rVar->tex_pos += rVar->step;
}

void replace_pixel_value_floor(t_map *rVar, char *s2, int j, int k)
{
	if (rVar->endian == 0)
	{
		rVar->addr[j] = s2[k];
		rVar->addr[j + 1] = s2[k + 1];
		rVar->addr[j + 2] = s2[k + 2];
	}
	else
	{
		rVar->addr[j] = s2[k + 2];
		rVar->addr[j + 1] = s2[k + 1];
		rVar->addr[j + 2] = s2[k];
	}
}

void change_char_in_addr_value(t_map *rVar, char *s2, int j, int k)
{
	int color;

	color = *(int *)(s2 + k);
	if (rVar->side)
		color = (color >> 1) & 8355711;
	if (rVar->endian == 0)
    {
		rVar->addr[j] = color;
		rVar->addr[j + 1] = color >> 8;
		rVar->addr[j + 2] = color >> 16;
	}
	else
    {
		rVar->addr[j] = color >> 16;
		rVar->addr[j + 1] = color >> 8;
		rVar->addr[j + 2] = color;
	}
}

void put_pixel(int x, t_map *rVar)
{
	int   i;
	int   j;
	int k;
	int texNum;

	texNum = get_wall_texture(rVar);
	i = rVar->drawStart;
	rVar->step = 1.0 * (rVar->textures[texNum].h) / rVar->lineHeight;
	rVar->tex_pos = (rVar->drawStart - HEIGHT / 2 + rVar->lineHeight / 2) * rVar->step;
	get_tex_x(rVar, texNum);
	while (i++ < rVar->drawEnd)
	{
		calculate_index_in_img(rVar, x, i, texNum);
		k = (rVar->tex_y * rVar->s_l + rVar->tex_x * (rVar->bpp / 8));
		j = (i * rVar->size_line) + (x * (rVar->bpp) / 8);
		change_char_in_addr_value(rVar, rVar->textures[texNum].addr, j, k);
	}
}
