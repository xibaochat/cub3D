#include "cub3D.h"

void	init_cat_img(t_map	*rVar)
{
	int w;
	int h;

	rVar->cat_img = mlx_xpm_file_to_image(rVar->mlx_ptr, "./textures/cat.xpm", &w, &h);
}
