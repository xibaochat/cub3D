/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_sprite_tex_index.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 10:05:41 by osshit            #+#    #+#             */
/*   Updated: 2020/04/08 05:07:08 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void change_sprite_tex_index(t_map *rVar)
{
	move_roll_cat(rVar);
	if (rVar->map[(int)rVar->new_posX][(int)rVar->new_posY] == 4)
		move_bad_cat(rVar);
	if (!rVar->round && (int)rVar->posX == 19 && ((int)rVar->posY == 4 || (int)rVar->posY == 6 || (int)rVar->posY == 5))
		move_door(rVar);
}
