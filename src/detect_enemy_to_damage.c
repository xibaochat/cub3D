#include "cub3D.h"

int find_enemy(t_map *rVar)
{
	int enemy_hit;

	enemy_hit = 0;
	while (enemy_hit == 0)
    {
		if(rVar->sideDistX < rVar->sideDistY)
		{
			rVar->sideDistX = rVar->sideDistX + rVar->deltaDistX;
			rVar->mapX = rVar->mapX + rVar->stepX;
			rVar->side = 0;
		}
		else
		{
			rVar->sideDistY = rVar->sideDistY + rVar->deltaDistY;
			rVar->mapY = rVar->mapY + rVar->stepY;
			rVar->side = 1;
		}
		if(rVar->map[rVar->mapX][rVar->mapY] == 1)
			rVar->hit = 1;
    }
}

t_spr *detect_enemy_to_damage(t_map *rVar)
{
    int x;

    x = -1;
    while (++x < WIDTH)
    {
        reset_rayon_var(rVar, x);
        calculate_side_dist(rVar);
        find_wall(rVar);
    }

}
