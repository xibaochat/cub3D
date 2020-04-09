/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_coordonne_calcilation_when_movement.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 10:26:57 by osshit            #+#    #+#             */
/*   Updated: 2020/04/08 07:07:10 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_up(t_map	 *rVar)
{
	double new_posX;
	double new_posY;

	new_posX = rVar->posX + (rVar->dirX) * moveSpeed;
	new_posY = rVar->posY + (rVar->dirY) * moveSpeed;
	rVar->new_posX = new_posX;
	rVar->new_posY = new_posY;
	if(!wall_collision(new_posX, rVar->posY, rVar->map))
			rVar->posX = new_posX;
	if(!wall_collision(rVar->posX, new_posY, rVar->map))
		rVar->posY = new_posY;
}

void move_down(t_map *rVar)
{
	double new_posX;
	double new_posY;

	new_posX = rVar->posX - (rVar->dirX) * moveSpeed;
	new_posY = rVar->posY - (rVar->dirY) * moveSpeed;
	rVar->new_posX = new_posX;
	rVar->new_posY = new_posY;
	if(!wall_collision(new_posX, rVar->posY, rVar->map))
		rVar->posX = new_posX;
	if(!wall_collision(rVar->posX, new_posY, rVar->map))
		rVar->posY = new_posY;
	if (wall_collision(new_posX, rVar->posY, rVar->map) ||
		wall_collision(rVar->posX, new_posY, rVar->map))
		insert_warn(rVar);
}

void move_left(t_map *rVar)
{
	rVar->oldDirX = rVar->dirX;
	rVar->dirX = rVar->dirX * cos(rVar->rotSpeed) - rVar->dirY * sin(rVar->rotSpeed);
	rVar->dirY = rVar->oldDirX * sin(rVar->rotSpeed) + rVar->dirY * cos(rVar->rotSpeed);
	rVar->oldPlaneX = rVar->planeX;
	rVar->planeX = (rVar->planeX) * cos(rVar->rotSpeed) - (rVar->planeY) * sin(rVar->rotSpeed);
	rVar->planeY = (rVar->oldPlaneX) * sin(rVar->rotSpeed) + (rVar->planeY) * cos(rVar->rotSpeed);
}

void move_right(t_map *rVar)
{
	rVar->oldDirX = rVar->dirX;
	rVar->dirX = (rVar->dirX) * cos((rVar->rotSpeed * -1)) - (rVar->dirY) * sin((rVar->rotSpeed * -1));
	rVar->dirY = (rVar->oldDirX) * sin((rVar->rotSpeed * -1)) + (rVar->dirY) * cos((rVar->rotSpeed * -1));
	rVar->oldPlaneX = rVar->planeX;
	rVar->planeX = (rVar->planeX) * cos((rVar->rotSpeed * -1)) - (rVar->planeY) * sin((rVar->rotSpeed * -1));
	rVar->planeY = (rVar->oldPlaneX) * sin((rVar->rotSpeed * -1)) + (rVar->planeY) * cos((rVar->rotSpeed * -1));
}
