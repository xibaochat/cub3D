/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_coor_calc_vertical_move.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 12:06:11 by osshit            #+#    #+#             */
/*   Updated: 2020/04/18 12:10:49 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_vertical_left(t_map *rvar)
{
	double	new_pos_x;
	double	new_pos_y;

	if (!rvar->map[(int)(rvar->pos_x - rvar->plane_x * MOVE_SPEED)]\
		[(int)rvar->pos_y])
		rvar->pos_x -= rvar->plane_x * MOVE_SPEED;
	if (!rvar->map[(int)rvar->pos_x]\
		[(int)(rvar->pos_y - rvar->plane_y * MOVE_SPEED)])
		rvar->pos_y -= rvar->plane_y * MOVE_SPEED;
}

void	move_vertical_right(t_map *rvar)
{
	if (!rvar->map[(int)(rvar->pos_x + rvar->plane_x * MOVE_SPEED)]\
	[(int)rvar->pos_y])
		rvar->pos_x += rvar->plane_x * MOVE_SPEED;
	if (!rvar->map[(int)rvar->pos_x]\
		[(int)(rvar->pos_y + rvar->plane_y * MOVE_SPEED)])
		rvar->pos_y += rvar->plane_y * MOVE_SPEED;
}
