/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_coordonne_calcilation_when_movement.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 10:26:57 by osshit            #+#    #+#             */
/*   Updated: 2020/04/18 12:29:42 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_map *rvar)
{
	double new_posx;
	double new_posy;

	new_posx = rvar->pos_x + (rvar->dir_x) * MOVE_SPEED;
	new_posy = rvar->pos_y + (rvar->dir_y) * MOVE_SPEED;
	rvar->new_pos_x = new_posx;
	rvar->new_pos_y = new_posy;
	if (!wall_collision(new_posx, rvar->pos_y, rvar->map))
		rvar->pos_x = new_posx;
	if (!wall_collision(rvar->pos_x, new_posy, rvar->map))
		rvar->pos_y = new_posy;
}

void	move_down(t_map *rvar)
{
	double new_posx;
	double new_posy;

	new_posx = rvar->pos_x - (rvar->dir_x) * MOVE_SPEED;
	new_posy = rvar->pos_y - (rvar->dir_y) * MOVE_SPEED;
	rvar->new_pos_x = new_posx;
	rvar->new_pos_y = new_posy;
	if (!wall_collision(new_posx, rvar->pos_y, rvar->map))
		rvar->pos_x = new_posx;
	if (!wall_collision(rvar->pos_x, new_posy, rvar->map))
		rvar->pos_y = new_posy;
	if (wall_collision(new_posx, rvar->pos_y, rvar->map) ||
		wall_collision(rvar->pos_x, new_posy, rvar->map))
		insert_warn(rvar);
}

void	move_left(t_map *rvar)
{
	rvar->old_dir_x = rvar->dir_x;
	rvar->dir_x = rvar->dir_x * cos(rvar->rot_speed)\
	- rvar->dir_y * sin(rvar->rot_speed);
	rvar->dir_y = rvar->old_dir_x * sin(rvar->rot_speed)\
	+ rvar->dir_y * cos(rvar->rot_speed);
	rvar->old_plane_x = rvar->plane_x;
	rvar->plane_x = (rvar->plane_x) * cos(rvar->rot_speed)\
	- (rvar->plane_y) * sin(rvar->rot_speed);
	rvar->plane_y = (rvar->old_plane_x) * sin(rvar->rot_speed)\
	+ (rvar->plane_y) * cos(rvar->rot_speed);
}

void	move_right(t_map *rvar)
{
	rvar->old_dir_x = rvar->dir_x;
	rvar->dir_x = (rvar->dir_x) * cos((rvar->rot_speed * -1))\
	- (rvar->dir_y) * sin((rvar->rot_speed * -1));
	rvar->dir_y = (rvar->old_dir_x) * sin((rvar->rot_speed * -1))\
	+ (rvar->dir_y) * cos((rvar->rot_speed * -1));
	rvar->old_plane_x = rvar->plane_x;
	rvar->plane_x = (rvar->plane_x) * cos((rvar->rot_speed * -1))\
	- (rvar->plane_y) * sin((rvar->rot_speed * -1));
	rvar->plane_y = (rvar->old_plane_x) * sin((rvar->rot_speed * -1))\
	+ (rvar->plane_y) * cos((rvar->rot_speed * -1));
}
