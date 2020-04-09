/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_weapons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 21:26:07 by osshit            #+#    #+#             */
/*   Updated: 2020/04/09 13:04:57 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void init_weapons_textures(t_map *rVar, t_weap *weap, int i)
{
	weap->id = i;
	if (weap->id == MACHINE_GUN_ID)
		init_weapon_texture(rVar, weap, 5, "machinegun");
	if (weap->id == COUTEAU_ID)
		init_weapon_texture(rVar, weap, 5, "couteau");
}

void init_weapons(t_map *rVar)
{
	int i;
    int j;

    i = -1;
	rVar->couteau = 0;
	rVar->shooting = 0;
	rVar->nb_press = 0;
	rVar->nb_weap_tex = 0;
    if (!(rVar->weaps = (t_weap *)malloc(sizeof(t_weap) * NB_WEAPONS)))
		free_program_var(rVar, "Malloc failed in weapons\n", NULL);
    while (++i < NB_WEAPONS)
		init_weapons_textures(rVar, rVar->weaps + i, i);
}
