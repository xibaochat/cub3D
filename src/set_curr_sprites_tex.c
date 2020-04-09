#include "cub3D.h"

void set_curr_sprites_tex(t_map *rVar)
{
	int i;
	int j;

	i = -1;
	while (++i < NB_SPRITE)
	{
		j = rVar->all_spr[i].nb_occur;
		if (i < NB_SPRITE - 1)
			set_sprite_img(rVar, rVar->all_spr + i, i);
		if (i == NB_SPRITE - 1)
			init_mutan_img(rVar);
	}

}
