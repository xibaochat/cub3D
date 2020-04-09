#include "cub3D.h"

static void calculation_drawing_sprite(t_spr *spr, t_map *rVar)
{
	spr->spriteX = spr->x - rVar->posX;
	spr->spriteY = spr->y -rVar->posY;
	spr->invDet = 1.0 / (rVar->planeX * rVar->dirY - rVar->dirX * rVar->planeY);
	spr->transformX =  spr->invDet * (rVar->dirY * spr->spriteX - rVar->dirX * spr->spriteY);
	spr->transformY = spr->invDet * (-rVar->planeY * spr->spriteX + rVar->planeX * spr->spriteY);
	spr->spriteScreenX = ((WIDTH / 2) * (1 + spr->transformX /  spr->transformY));
	spr->spriteHeight = abs((int)(HEIGHT / (spr->transformY)));
	spr->drawStartY = -spr->spriteHeight / 2 + HEIGHT / 2;
	if(spr->drawStartY < 0)
		spr->drawStartY = 0;
	spr->drawEndY = spr->spriteHeight / 2 + HEIGHT / 2;
	if(spr->drawEndY >= HEIGHT)
		spr->drawEndY = HEIGHT - 1;
	spr->spriteWidth = abs((int)(HEIGHT / spr->transformY));
	spr->drawStartX = -spr->spriteWidth / 2 + spr->spriteScreenX;
	if(spr->drawStartX < 0)
		spr->drawStartX = 0;
	spr->drawEndX = spr->spriteWidth / 2 + spr->spriteScreenX;
	if(spr->drawEndX >= WIDTH)
		spr->drawEndX = WIDTH - 1;
	spr->stripe = spr->drawStartX;
}

static int get_total_nb_sprites(t_map *rVar)
{
	int i;
	int total_nb_sprite;

	i = -1;
	total_nb_sprite = 0;
	while (++i < NB_SPRITE)
		total_nb_sprite += rVar->all_spr[i].nb_occur;
	return (total_nb_sprite);
}

void store_chaque_indi_spr_addr_in_an_array(t_map *rVar, int total_nb_sprite)
{
	int j;
	int k;
	int i;

	i = -1;
	j = -1;

	if (!(rVar->sprite_order = (t_spr **)malloc(sizeof(t_spr *) * total_nb_sprite)))
		free_program_var(rVar, "Malloc failed in function draw_sprite\n", NULL);
	while (++j < NB_SPRITE)
	{
		k = -1;
		while (++k < rVar->all_spr[j].nb_occur)
			rVar->sprite_order[++i] = rVar->all_spr[j].indi_spr + k;
	}
}

void draw_sprites(t_map *rVar)
{
	t_prop  *current_prop;
	int     i;
	int total_nb_sprite;

	i = -1;
	total_nb_sprite = get_total_nb_sprites(rVar);
	rVar->nb_spr = total_nb_sprite;
	store_chaque_indi_spr_addr_in_an_array(rVar, total_nb_sprite);
	rVar->sprite_order = get_sprites_order(rVar, rVar->sprite_order, total_nb_sprite);
	while (++i < total_nb_sprite)
	{
		if (rVar->sprite_order[i]->hitpoint > 0)
		{
			calculation_drawing_sprite(rVar->sprite_order[i], rVar);
			draw_vertical_sprite(rVar->sprite_order[i], rVar);
		}
	}
}
