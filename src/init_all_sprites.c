/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 21:41:42 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 18:56:39 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	init_chaque_spr(t_map *r, t_prop *spr, int index)
{
	get_indi_sprite_coord(spr->indi_spr, r, index + 2);
	init_hp(spr);
	init_origin_sprite(spr);
}

static void	init_chaque_type_spr(t_map *r, t_prop *spr, int i)
{
	spr->nb_occur = cal_nb_obj(r->map_str, i);
	init_chaque_spr(r, spr, i);
}

void		init_all_sprites(t_map *r)
{
	int i;

	i = -1;
	while (++i < NB_SPRITE)
		init_chaque_type_spr(r, r->all_spr + i, i);
}
