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

#include "cub3D.h"

void	move_up(t_map *rvar)
{
	double new_posx;
	double new_posy;

	new_posx = rvar->posX + (rvar->dirX) * moveSpeed;
	new_posy = rvar->posY + (rvar->dirY) * moveSpeed;
	rvar->new_posX = new_posx;
	rvar->new_posY = new_posy;
	if (!wall_collision(new_posx, rvar->posY, rvar->map))
		rvar->posX = new_posx;
	if (!wall_collision(rvar->posX, new_posy, rvar->map))
		rvar->posY = new_posy;
}

void	move_down(t_map *rvar)
{
	double new_posx;
	double new_posy;

	new_posx = rvar->posX - (rvar->dirX) * moveSpeed;
	new_posy = rvar->posY - (rvar->dirY) * moveSpeed;
	rvar->new_posX = new_posx;
	rvar->new_posY = new_posy;
	if (!wall_collision(new_posx, rvar->posY, rvar->map))
		rvar->posX = new_posx;
	if (!wall_collision(rvar->posX, new_posy, rvar->map))
		rvar->posY = new_posy;
	if (wall_collision(new_posx, rvar->posY, rvar->map) ||
		wall_collision(rvar->posX, new_posy, rvar->map))
		insert_warn(rvar);
}

void	move_left(t_map *rvar)
{
	rvar->oldDirX = rvar->dirX;
	rvar->dirX = rvar->dirX * cos(rvar->rotSpeed)\
	- rvar->dirY * sin(rvar->rotSpeed);
	rvar->dirY = rvar->oldDirX * sin(rvar->rotSpeed)\
	+ rvar->dirY * cos(rvar->rotSpeed);
	rvar->oldPlaneX = rvar->planeX;
	rvar->planeX = (rvar->planeX) * cos(rvar->rotSpeed)\
	- (rvar->planeY) * sin(rvar->rotSpeed);
	rvar->planeY = (rvar->oldPlaneX) * sin(rvar->rotSpeed)\
	+ (rvar->planeY) * cos(rvar->rotSpeed);
}

void	move_right(t_map *rvar)
{
	rvar->oldDirX = rvar->dirX;
	rvar->dirX = (rvar->dirX) * cos((rvar->rotSpeed * -1))\
	- (rvar->dirY) * sin((rvar->rotSpeed * -1));
	rvar->dirY = (rvar->oldDirX) * sin((rvar->rotSpeed * -1))\
	+ (rvar->dirY) * cos((rvar->rotSpeed * -1));
	rvar->oldPlaneX = rvar->planeX;
	rvar->planeX = (rvar->planeX) * cos((rvar->rotSpeed * -1))\
	- (rvar->planeY) * sin((rvar->rotSpeed * -1));
	rvar->planeY = (rvar->oldPlaneX) * sin((rvar->rotSpeed * -1))\
	+ (rvar->planeY) * cos((rvar->rotSpeed * -1));
}
