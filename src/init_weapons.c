/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_weapons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 21:26:07 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 08:21:18 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_weapons_textures(t_map *rvar, t_weap *weap, int i)
{
	weap->id = i;
	if (weap->id == MACHINE_GUN_ID)
		init_weapon_texture(rvar, weap, 5, "machinegun");
	if (weap->id == COUTEAU_ID)
		init_weapon_texture(rvar, weap, 5, "couteau");
}

void		init_weapons(t_map *rvar)
{
	int i;
	int j;

	i = -1;
	rvar->couteau = 0;
	rvar->shooting = 0;
	rvar->nb_press = 0;
	rvar->nb_weap_tex = 0;
	if (!(rvar->weaps = (t_weap *)malloc(sizeof(t_weap) * NB_WEAPONS)))
		free_program_var(rvar, "Malloc failed in weapons\n", NULL);
	while (++i < NB_WEAPONS)
		init_weapons_textures(rvar, rvar->weaps + i, i);
}
