/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_new_pos_and_value_after_pick_spr.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 09:42:17 by osshit            #+#    #+#             */
/*   Updated: 2020/04/17 09:42:20 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	re_init_animated_sprites(t_map *rvar)
{
	rvar->nb_bad_cat = 0;
}

void		set_new_pos_and_value_after_pick_spr(t_map *rvar)
{
	if (rvar->map[(int)rvar->new_posX][(int)rvar->new_posY] == 3)
	{
		rvar->score += 50;
		rvar->map[(int)rvar->new_posX][(int)rvar->new_posY] = 0;
		set_entity_hitpoint(rvar, 1, \
		(int)rvar->new_posX, (int)rvar->new_posY, 0);
	}
	if (rvar->map[(int)rvar->new_posX][(int)rvar->new_posY] == 5)
	{
		rvar->lucky_value++;
		rvar->map[(int)rvar->new_posX][(int)rvar->new_posY] = 0;
		set_entity_hitpoint(rvar, 3, (int)rvar->new_posX, \
		(int)rvar->new_posY, 0);
	}
	if (rvar->map[(int)rvar->new_posX][(int)rvar->new_posY] != 4)
		re_init_animated_sprites(rvar);
}
