/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_hurt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 11:24:03 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 18:11:41 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		player_is_knocking_on_wall_or_barrier(t_map *r, double new_pos_x,\
		double new_pos_y)
{
	return (((wall_collision(new_pos_x, r->pos_y, r->map) ||
			wall_collision(r->pos_x, new_pos_y, r->map)) &&
			((r->map[(int)new_pos_x][(int)new_pos_y] == POTATO_ID) ||
			(r->map[(int)new_pos_x][(int)new_pos_y] == TNT) ||
			(r->map[(int)new_pos_x][(int)new_pos_y] == BAD_CAT_ID) ||
			(r->map[(int)new_pos_x][(int)new_pos_y] == WALL_ID))));
}

void	inser_hurt(t_map *r, double new_pos_x, double new_pos_y)
{
	if (player_is_knocking_on_wall_or_barrier(r, new_pos_x, new_pos_y))
		insert_warn(r);
	if (r->round == 0 && r->score == 450 &&
		(int)r->new_pos_x == 19 && (int)r->new_pos_y == 7 &&
		((r->lucky_value == (r->all_spr + 3)->nb_occur)))
		nice_job(r);
}
