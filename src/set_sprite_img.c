#include "cub3D.h"

void set_sprite_img(t_map *rVar, t_prop *spr, int i)
{
	char *filepath;
	int j;

	j = -1;

	if (i != 5)
	{
		if (!i)
			filepath = rVar->S;
		else if (i == 1)
			filepath = "./textures/cat.xpm";
		else if (i == 2)
			filepath = rVar->bad_cat[rVar->nb_bad_cat].path;
		else if (i == 3)
			filepath = rVar->roll_cat[rVar->nb_roll_cat].path;
		else if (i == 4)
			filepath = rVar->door[rVar->nb_door].path;
		spr->img = mlx_xpm_file_to_image(rVar->mlx_ptr, filepath, &spr->width, &spr->height);
		if (!spr->img)
			free_program_var(rVar, "Can't find the spr filepath: ", filepath);
		spr->addr = mlx_get_data_addr(spr->img, &(spr->bpp), &(spr->s_l), &(spr->endian));
	}
}
