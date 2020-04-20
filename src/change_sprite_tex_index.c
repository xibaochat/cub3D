/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_sprite_tex_index.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 10:05:41 by osshit            #+#    #+#             */
/*   Updated: 2020/04/17 08:28:25 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	change_sprite_tex_index(t_map *rvar)
{
	move_roll_cat(rvar);
	if (rvar->map[(int)rvar->new_pos_x][(int)rvar->new_pos_y] == 4)
		move_bad_cat(rvar);
	if (!rvar->round && (int)rvar->pos_x == 19 &&
		((int)rvar->pos_y == 4 || (int)rvar->pos_y == 6 || (int)rvar->pos_y == 5))
		move_door(rvar);
}
