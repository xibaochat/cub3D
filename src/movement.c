/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:21:23 by xinwang           #+#    #+#             */
/*   Updated: 2020/04/08 07:07:03 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int wall_collision(double x, double y, int **map)
{
	return (map[(int)(x)][(int)y] != 0);
}

void	move_action(t_map	*rVar)
{
	if (rVar->open_up == 1)
		move_up(rVar);
	if (rVar->open_down == 1)
		move_down(rVar);
	if (rVar->open_left == 1)
		move_left(rVar);
	if (rVar->open_right == 1)
		move_right(rVar);
	if (rVar->open_A == 1)
		move_vertical_left(rVar);
	if (rVar->open_D == 1)
		move_vertical_right(rVar);
}

static int has_moved(t_map *rVar)
{
	return (rVar->open_up == 1 || rVar->open_down == 1 ||
			rVar->open_left == 1 || rVar->open_right == 1 ||
			rVar->open_A == 1 || rVar->open_D == 1);
}

int movement(t_map *rVar)
{
	if (has_moved(rVar))
	{
		mlx_destroy_image (rVar->mlx_ptr, rVar->image_ptr );
		move_action(rVar);
		manage_sound_based_on_pos(rVar);
		set_new_pos_and_value_after_pick_spr(rVar);
		inser_hurt(rVar, rVar->new_posX, rVar->new_posY);
	}
	new_graph(rVar);
	return (0);
}
