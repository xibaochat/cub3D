#include "cub3D.h"

static void init_floor_imgs(t_map *rVar)
{
	rVar->floor_img_ptr =  mlx_xpm_file_to_image(rVar->mlx_ptr, rVar->F, &(rVar->width_floor), &(rVar->height_floor));
	rVar->floor_texture = mlx_get_data_addr(rVar->floor_img_ptr, &(rVar->floor_bpp), &(rVar->s_l_floor), &(rVar->endian));
}

static void init_score(t_map *rVar)
{
	int w;
	int h;

	rVar->score_img = mlx_xpm_file_to_image(rVar->mlx_ptr, "./textures/score.xpm", &w, &h);
}

void    init_hud_imgs(t_map *rVar)
{

	init_floor_imgs(rVar);
	init_score(rVar);
}
