/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 12:48:39 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 19:45:29 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
	int	i;

	i = -1;
	if (rvar->bad_cat)
	{
		while (++i <= 30)
		{
			if (rvar->bad_cat[i].path)
			{
				free(rvar->bad_cat[i].path);
				rvar->bad_cat[i].path = NULL;
			}
		}
		free(rvar->bad_cat);
		rvar->bad_cat = NULL;
	}
	i = -1;
	if (rvar->roll_cat)
	{
		while (++i <= 15)
		{
			if (rvar->roll_cat[i].path)
			{
				free(rvar->roll_cat[i].path);
				rvar->roll_cat[i].path = NULL;
			}
		}
		free(rvar->roll_cat);
		rvar->roll_cat = NULL;
	}
	/* free_weapons(rvar); */
	free_sprites_selon_type_spr(rvar);
}
