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

#include "cub3D.h"

void	change_sprite_tex_index(t_map *rvar)
{
	move_roll_cat(rvar);
	if (rvar->map[(int)rvar->new_posX][(int)rvar->new_posY] == 4)
		move_bad_cat(rvar);
	if (!rvar->round && (int)rvar->posX == 19 &&
		((int)rvar->posY == 4 || (int)rvar->posY == 6 || (int)rvar->posY == 5))
		move_door(rvar);
}
