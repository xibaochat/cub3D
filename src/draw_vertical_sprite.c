/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_sprite.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:13:26 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 14:36:06 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void		draw_vertical_sprite(t_spr *indi_spr, t_map *rvar)
{
	int y;
	int tex_x;
	int tex_y;

	while (indi_spr->stripe++ < indi_spr->draw_end_x - 1)
	{
		tex_x = (int)((256 * (indi_spr->stripe -
		(-indi_spr->sprite_width / 2 + indi_spr->sprite_screen_x)) *
		indi_spr->origin_sprite->width / indi_spr->sprite_width) / 256);
		if (indi_spr->transform_y > 0 && indi_spr->stripe > 0 &&
			indi_spr->stripe < rvar->width
			&& indi_spr->transform_y < rvar->spr_buffer[indi_spr->stripe])
		{
			y = indi_spr->draw_start_y;
			while (y++ < indi_spr->draw_end_y - 1)
			{
				rvar->d = y * 256 - rvar->height * 128 + indi_spr->sprite_height * 128;
				tex_y = ((rvar->d * indi_spr->origin_sprite->height)
				/ indi_spr->sprite_height) / 256;
				rvar->k = color_index_in_str(tex_x, tex_y,
				indi_spr->origin_sprite->s_l, rvar);
				replace_color(*indi_spr, y, rvar->k, rvar);
			}
		}
	}
}
