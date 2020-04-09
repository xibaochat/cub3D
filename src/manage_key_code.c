#include "cub3D.h"

int manage_rotation_arrow(int keycode, t_map *rVar)
{
	if (keycode == LEFT_ARROW_KEY)
	{
		change_left_rotation_dir(rVar);
//		move_left(rVar);
	}
	if (keycode == RIGHT_ARROW_KEY)
		change_right_rotation_dir(rVar);
	mlx_destroy_image (rVar->mlx_ptr, rVar->image_ptr );
	new_graph(rVar);
	return (0);
}
