/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 21:41:42 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 09:28:01 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_chaque_spr(t_map *r, t_prop *spr, int index)
{
	get_indi_sprite_coord(spr->indi_spr, r, index + 2);
	init_hp(spr);
	init_origin_sprite(spr);
}

static void	init_chaque_type_spr(t_map *r, t_prop *spr, int i)
{
	spr->nb_occur = cal_nb_obj(r->map_str, i);
	if (!(spr->indi_spr = (t_spr *)malloc(sizeof(t_spr) * (spr->nb_occur))))
		free_program_var(r, \
	"Malloc failed in the function init_chaque_type_spr\n", NULL);
	init_chaque_spr(r, spr, i);
}

void		init_all_sprites(t_map *r)
{
	int i;
	int j;

	i = -1;
	if (!(r->all_spr = (t_prop *)malloc(sizeof(t_prop) * NB_SPRITE)))
		free_program_var(r, \
	"Malloc failed in the function init_all_sprites\n", NULL);
	while (++i < NB_SPRITE)
		init_chaque_type_spr(r, r->all_spr + i, i);
}
