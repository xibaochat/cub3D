#include "cub3D.h"

void move_vertical_left(t_map *rVar)
{
	double	new_posX;
	double	new_posY;

	if (!rVar->map[(int)(rVar->posX - rVar->planeX * moveSpeed)][(int)rVar->posY])
		rVar->posX -= rVar->planeX * moveSpeed;
	if (!rVar->map[(int)rVar->posX][(int)(rVar->posY - rVar->planeY * moveSpeed)])
		rVar->posY -= rVar->planeY * moveSpeed;
}

void move_vertical_right(t_map *rVar)
{
	if (!rVar->map[(int)(rVar->posX + rVar->planeX * moveSpeed)][(int)rVar->posY])
		rVar->posX += rVar->planeX * moveSpeed;
	if (!rVar->map[(int)rVar->posX][(int)(rVar->posY + rVar->planeY * moveSpeed)])
		rVar->posY += rVar->planeY * moveSpeed;
}
