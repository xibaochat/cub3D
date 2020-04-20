/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 09:34:17 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 09:34:20 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	calculation_drawing_sprite(t_spr *spr, t_map *rvar)
{
	spr->spriteX = spr->x - rvar->posX;
	spr->spriteY = spr->y - rvar->posY;
	spr->invDet = 1.0 / (rvar->planeX * rvar->dirY - rvar->dirX * rvar->planeY);
	spr->transformX = spr->invDet * \
	(rvar->dirY * spr->spriteX - rvar->dirX * spr->spriteY);
	spr->transformY = spr->invDet * (-rvar->planeY * spr->spriteX\
	+ rvar->planeX * spr->spriteY);
	spr->spriteScreenX = ((rvar->width / 2) * \
	(1 + spr->transformX / spr->transformY));
	spr->spriteHeight = abs((int)(rvar->height / (spr->transformY)));
	spr->drawStartY = -spr->spriteHeight / 2 + rvar->height / 2;
	if (spr->drawStartY < 0)
		spr->drawStartY = 0;
	spr->drawEndY = spr->spriteHeight / 2 + rvar->height / 2;
	if (spr->drawEndY >= rvar->height)
		spr->drawEndY = rvar->height - 1;
	spr->spriteWidth = abs((int)(rvar->height / spr->transformY));
	spr->drawStartX = -spr->spriteWidth / 2 + spr->spriteScreenX;
	if (spr->drawStartX < 0)
		spr->drawStartX = 0;
	spr->drawEndX = spr->spriteWidth / 2 + spr->spriteScreenX;
	if (spr->drawEndX >= rvar->width)
		spr->drawEndX = rvar->width - 1;
	spr->stripe = spr->drawStartX;
}

static int	get_total_nb_sprites(t_map *rvar)
{
	int i;
	int total_nb_sprite;

	i = -1;
	total_nb_sprite = 0;
	while (++i < NB_SPRITE)
		total_nb_sprite += rvar->all_spr[i].nb_occur;
	return (total_nb_sprite);
}

void		store_chaque_indi_spr_addr_in_an_array(t_map *rvar,\
			int total_nb_sprite)
{
	int j;
	int k;
	int i;

	i = -1;
	j = -1;
	if (!(rvar->sprite_order = (t_spr **)malloc(sizeof(t_spr *) \
	* total_nb_sprite)))
		free_program_var(rvar, "Malloc failed in function draw_sprite\n", NULL);
	while (++j < NB_SPRITE)
	{
		k = -1;
		while (++k < rvar->all_spr[j].nb_occur)
			rvar->sprite_order[++i] = rvar->all_spr[j].indi_spr + k;
	}
}

void		draw_sprites(t_map *rvar)
{
	t_prop	*current_prop;
	int		i;
	int		total_nb_sprite;

	i = -1;
	total_nb_sprite = get_total_nb_sprites(rvar);
	rvar->nb_spr = total_nb_sprite;
	store_chaque_indi_spr_addr_in_an_array(rvar, total_nb_sprite);
	rvar->sprite_order = get_sprites_order(rvar, \
	rvar->sprite_order, total_nb_sprite);
	while (++i < total_nb_sprite)
	{
		if (rvar->sprite_order[i]->hitpoint > 0)
		{
			calculation_drawing_sprite(rvar->sprite_order[i], rvar);
			draw_vertical_sprite(rvar->sprite_order[i], rvar);
		}
	}
}
