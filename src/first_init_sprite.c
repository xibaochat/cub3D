/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_program_var_to_null.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 09:24:23 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 09:25:09 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


void first_init_sprite(t_map *r)
{
	int	i;
	int j;
	t_prop *spr;

	i = -1;
	if (!(r->all_spr = (t_prop *)malloc(sizeof(t_prop) * NB_SPRITE)))
		free_program_var(r, "Malloc failed in the function init_all_sprites\n", NULL);
	while (++i < NB_SPRITE)
	{
		spr = r->all_spr + i;
		spr->nb_occur = cal_nb_obj(r->map_str, i);
		j = spr->nb_occur;
		if (!(spr->indi_spr = (t_spr *)malloc(sizeof(t_spr) * (spr->nb_occur))))
			free_program_var(r, "Malloc failed in the function init_chaque_type_spr\n", NULL);
		while (--j >= 0)
		{
			spr->indi_spr[j].img = NULL;
			spr->indi_spr[j].hitpoint = 100;
			spr->indi_spr[j].origin_sprite = spr;
		}
	}
}
