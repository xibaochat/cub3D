/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_sprite_tex_index.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 10:05:41 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 18:27:12 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	change_sprite_tex_index(t_map *r)
{
	move_roll_cat(r);
	if (r->map[(int)r->new_pos_x][(int)r->new_pos_y] == 4)
		move_bad_cat(r);
	if (!r->round && (int)r->pos_x == 19 &&
		((int)r->pos_y == 4 || (int)r->pos_y == 6 || (int)r->pos_y == 5))
		move_door(r);
}
