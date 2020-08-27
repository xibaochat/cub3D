/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_entity_hitpoints.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 11:01:19 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 11:11:43 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static t_spr	*get_entity(t_map *rvar, int i_sprite, int x, int y)
{
	int		i;
	int		nb_occur;
	t_spr	*curr_spr;

	i = -1;
	nb_occur = rvar->all_spr[i_sprite].nb_occur;
	while (++i < nb_occur)
	{
		curr_spr = rvar->all_spr[i_sprite].indi_spr + i;
		if (curr_spr->x_map == x && curr_spr->y_map == y)
			return (curr_spr);
	}
	return (NULL);
}

void			set_entity_hitpoint_as_zero(t_map *rvar, int i_sprite, \
				int x, int y)
{
	t_spr	*entity;

	entity = get_entity(rvar, i_sprite, x, y);
	entity->hitpoint = 0;
}

double			get_object_distance(t_map *rvar, t_spr *entity)
{
	int	i;

	i = -1;
	while (++i < rvar->nb_spr)
	{
		if (rvar->sprite_order[i] == entity)
			return (rvar->sprite_distance[i]);
	}
	return (0);
}

void			decrease_enemy_hitpoint(t_map *rvar, int hitpoint)
{
	t_spr	*entity;

	entity = NULL;
	if (rvar->shooting)
		entity = get_entity(rvar, 5, rvar->enemy.x, rvar->enemy.y);
	else
		entity = get_entity(rvar, 0, rvar->enemy.x, rvar->enemy.y);
	if (entity && entity->hitpoint > 7)
	{
		if ((rvar->couteau && get_object_distance(rvar, entity) <= 3) ||
			(rvar->shooting))
			entity->hitpoint = entity->hitpoint - hitpoint;
		if (entity->hitpoint <= 0)
			rvar->map[rvar->enemy.x][rvar->enemy.y] = 0;
	}
}
