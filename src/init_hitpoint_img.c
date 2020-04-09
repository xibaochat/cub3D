#include "cub3D.h"

void init_hitpoint_imgs(t_map *rVar)
{
	int w;
	int h;

	rVar->hitpoint_img = (void **)malloc(sizeof(void *) * 4);
	rVar->hitpoint_img[0] = mlx_xpm_file_to_image(rVar->mlx_ptr, "./textures/hitpoint.xpm", &w, &h);
	rVar->hitpoint_img[1] = mlx_xpm_file_to_image(rVar->mlx_ptr, "./textures/hitpoint01.xpm", &w, &h);
	rVar->hitpoint_img[2] = mlx_xpm_file_to_image(rVar->mlx_ptr, "./textures/hitpoint02.xpm", &w, &h);
	rVar->hitpoint_img[3] = mlx_xpm_file_to_image(rVar->mlx_ptr, "./textures/hitpoint03.xpm", &w, &h);
}
