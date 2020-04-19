/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 12:48:39 by osshit            #+#    #+#             */
/*   Updated: 2020/04/18 12:48:43 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_hitpoint(t_map *rvar)
{
	if (rvar->hitpoint_img)
	{
		free(rvar->hitpoint_img);
		rvar->hitpoint_img = NULL;
	}
}

void	free_weapons(t_map *rvar)
{
	int i;
	int j;

	i = -1;
	if (rvar->weaps)
	{
		while (++i < NB_WEAPONS)
		{
			if ((rvar->weaps + i)->tex)
			{
				free(rvar->weaps[i].tex);
				rvar->weaps[i].tex = NULL;
			}
		}
		free(rvar->weaps);
		rvar->weaps = NULL;
	}
}

void	free_sprites_selon_type_spr(t_map *rvar)
{
	int i;

	i = -1;
	if (rvar->all_spr)
	{
		while (++i < NB_SPRITE)
		{
			if ((rvar->all_spr + i)->indi_spr)
			{
				free((rvar->all_spr + i)->indi_spr);
				(rvar->all_spr + i)->indi_spr = NULL;
			}
		}
		free(rvar->all_spr);
		rvar->all_spr = NULL;
	}
}

void	free_sprite_order(t_map *rvar)
{
	if (rvar->sprite_order)
	{
		free(rvar->sprite_order);
		rvar->sprite_order = NULL;
	}
}

void	free_spr_img(t_map *rvar)
{
	if (rvar->bad_cat)
	{
		free(rvar->bad_cat);
		rvar->bad_cat = NULL;
	}
	if (rvar->roll_cat)
	{
		free(rvar->roll_cat);
		rvar->roll_cat = NULL;
	}
	if (rvar->door)
	{
		free(rvar->door);
		rvar->door = NULL;
	}
	free_weapons(rvar);
	free_sprites_selon_type_spr(rvar);
}
