#include "cub3D.h"

void	init_turns_img(t_map *rVar)
{
	int	w;
	int	h;

	rVar->turns_img = mlx_xpm_file_to_image(rVar->mlx_ptr, "./textures/heart.xpm", &w, &h);
}
