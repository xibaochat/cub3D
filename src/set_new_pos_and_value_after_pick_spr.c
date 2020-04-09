#include "cub3D.h"

static void re_init_animated_sprites(t_map *rVar)
{
    rVar->nb_bad_cat = 0;
}

void set_new_pos_and_value_after_pick_spr(t_map *rVar)
{
	if (rVar->map[(int)rVar->new_posX][(int)rVar->new_posY] == 3)
	{
		rVar->score += 50;
		rVar->map[(int)rVar->new_posX][(int)rVar->new_posY] = 0;
		set_entity_hitpoint(rVar, 1, (int)rVar->new_posX, (int)rVar->new_posY, 0);
	}
	if (rVar->map[(int)rVar->new_posX][(int)rVar->new_posY] == 5)
	{
		rVar->lucky_value++;
		rVar->map[(int)rVar->new_posX][(int)rVar->new_posY] = 0;
		set_entity_hitpoint(rVar, 3, (int)rVar->new_posX, (int)rVar->new_posY, 0);
	}
	if (rVar->map[(int)rVar->new_posX][(int)rVar->new_posY] != 4)
		re_init_animated_sprites(rVar);
}
