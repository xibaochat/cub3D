/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_sprite.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:13:26 by osshit            #+#    #+#             */
/*   Updated: 2020/04/17 12:14:43 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	color_index_in_str(int x, int y, int s_l, t_map *rvar)
{
	return (s_l * y + x * (rvar->bpp / 8));
}

static void	replace_color(t_spr indi_spr, int y, int k, t_map *rvar)
{
	int j;

	j = color_index_in_str(indi_spr.stripe, y, rvar->size_line, rvar);
	if ((rvar->endian == 0) && indi_spr.origin_sprite == rvar->all_spr + 5)
	{
		if ((unsigned int)(indi_spr.addr[k]) != 0xFFFFFFEE)
		{
			rvar->addr[j] = indi_spr.addr[k];
			rvar->addr[j + 1] = indi_spr.addr[k + 1];
			rvar->addr[j + 2] = indi_spr.addr[k + 2];
		}
	}
	else if ((rvar->endian == 0) &&
	(unsigned int)indi_spr.origin_sprite->addr[k] != 0x000000)
	{
		rvar->addr[j] = indi_spr.origin_sprite->addr[k];
		rvar->addr[j + 1] = indi_spr.origin_sprite->addr[k + 1];
		rvar->addr[j + 2] = indi_spr.origin_sprite->addr[k + 2];
	}
	else if ((unsigned int)indi_spr.origin_sprite->addr[k] != 0x000000)
	{
		rvar->addr[j + 2] = indi_spr.origin_sprite->addr[k + 2];
		rvar->addr[j + 1] = indi_spr.origin_sprite->addr[k + 1];
		rvar->addr[j] = indi_spr.origin_sprite->addr[k];
	}
}

void		draw_vertical_sprite(t_spr *indi_spr, t_map *rVar)
{
	int y;
	int tex_x;
	int tex_y;

	while (indi_spr->stripe++ < indi_spr->drawEndX - 1)
	{
		tex_x = (int)((256 * (indi_spr->stripe -
		(-indi_spr->spriteWidth / 2 + indi_spr->spriteScreenX)) *
		indi_spr->origin_sprite->width / indi_spr->spriteWidth) / 256);
		if (indi_spr->transformY > 0 && indi_spr->stripe > 0 &&
			indi_spr->stripe < WIDTH
			&& indi_spr->transformY < rVar->spr_buffer[indi_spr->stripe])
		{
			y = indi_spr->drawStartY;
			while (y++ < indi_spr->drawEndY - 1)
			{
				rVar->d = y * 256 - HEIGHT * 128 + indi_spr->spriteHeight * 128;
				tex_y = ((rVar->d * indi_spr->origin_sprite->height)
				/ indi_spr->spriteHeight) / 256;
				rVar->k = color_index_in_str(tex_x, tex_y,
				indi_spr->origin_sprite->s_l, rVar);
				replace_color(*indi_spr, y, rVar->k, rVar);
			}
		}
	}
}
