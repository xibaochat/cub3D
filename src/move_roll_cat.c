#include "cub3D.h"

void move_roll_cat(t_map *rVar)
{
	rVar->roll_cat->nb_tex++;
	if (rVar->roll_cat->nb_tex % 3 == 0)
		rVar->nb_roll_cat++;
	if (rVar->nb_roll_cat == 16)
		rVar->nb_roll_cat = 0;

}
