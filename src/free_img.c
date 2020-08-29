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
	free_str(rvar->hitpoint_img);
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
				free_str(rvar->weaps[i].tex);
		}
		free_str(rvar->weaps);
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
				free_str((rvar->all_spr + i)->indi_spr);
		}
		free_str(rvar->all_spr);
	}
}

void	free_sprite_order(t_map *rvar)
{
	free_str(rvar->sprite_order);
}

void	free_spr_img(t_map *rvar)
{
	int	i;

	i = -1;
	if (rvar->bad_cat)
	{
		while (++i <= 30)
			free_str(rvar->bad_cat[i].path);
		free_str(rvar->bad_cat);
	}
	i = -1;
	if (rvar->roll_cat)
	{
		while (++i <= 15)
			free_str(rvar->roll_cat[i].path);
		free_str(rvar->roll_cat);
	}
	free_weapons(rvar);
	free_sprites_selon_type_spr(rvar);
}
