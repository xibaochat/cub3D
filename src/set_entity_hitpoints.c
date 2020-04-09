#include "cub3D.h"

static t_spr *get_entity(t_map *rVar, int i_sprite, int x, int y)
{
	int i;
	int nb_occur;
	t_spr *curr_spr;

	i = -1;
	nb_occur = rVar->all_spr[i_sprite].nb_occur;
	while (++i < nb_occur)
	{
		curr_spr = rVar->all_spr[i_sprite].indi_spr + i;
		if (curr_spr->x_map == x && curr_spr->y_map == y)
			return (curr_spr);
	}
	return (NULL);
}

void set_entity_hitpoint(t_map *rVar, int i_sprite, int x, int y, int hitpoint)
{
	t_spr *entity;

	entity = get_entity(rVar, i_sprite, x, y);
	entity->hitpoint = hitpoint;
}

double get_object_distance(t_map *rVar, t_spr *entity)
{
	int i;

	i = -1;
	while (++i < rVar->nb_spr)
	{
		if (rVar->sprite_order[i] == entity)
			return (rVar->sprite_distance[i]);
	}
	return (0);
}

void decrease_enemy_hitpoint(t_map *rVar, int hitpoint)
{
	t_spr *entity;

	entity = NULL;
	if (rVar->shooting)
		entity = get_entity(rVar, 5, rVar->enemy.x, rVar->enemy.y);
	else
		entity = get_entity(rVar, 0, rVar->enemy.x, rVar->enemy.y);
	if (entity && entity->hitpoint > 7)
	{
		if ((rVar->couteau && get_object_distance(rVar, entity) <= 3) ||
			(rVar->shooting))
			entity->hitpoint = entity->hitpoint - hitpoint;
		if (entity->hitpoint <= 0)
			rVar->map[rVar->enemy.x][rVar->enemy.y] = 0;
	}
}
