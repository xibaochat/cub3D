/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_new_pos_and_value_after_pick_spr.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 09:42:17 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 11:12:08 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	re_init_animated_sprites(t_map *rvar)
{
	rvar->nb_bad_cat = 0;
}

void		set_new_pos_and_value_after_pick_spr(t_map *rvar)
{
	if (rvar->map[(int)rvar->new_pos_x][(int)rvar->new_pos_y] == 3)
	{
		rvar->score += 50;
		rvar->map[(int)rvar->new_pos_x][(int)rvar->new_pos_y] = 0;
		set_entity_hitpoint_as_zero(rvar, 1, \
		(int)rvar->new_pos_x, (int)rvar->new_pos_y);
	}
	if (rvar->map[(int)rvar->new_pos_x][(int)rvar->new_pos_y] == 5)
	{
		rvar->lucky_value++;
		rvar->map[(int)rvar->new_pos_x][(int)rvar->new_pos_y] = 0;
		set_entity_hitpoint_as_zero(rvar, 3, (int)rvar->new_pos_x, \
		(int)rvar->new_pos_y);
	}
	if (rvar->map[(int)rvar->new_pos_x][(int)rvar->new_pos_y] != 4)
		re_init_animated_sprites(rvar);
}
