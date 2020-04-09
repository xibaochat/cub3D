#include "cub3D.h"

void move_door(t_map *rVar)
{
	rVar->nb_door++;
	if (rVar->nb_door == 5)
		rVar->nb_door = 4;
	if (rVar->lucky_value != (rVar->all_spr + 3)->nb_occur)
		rVar->nb_door = 0;


}
