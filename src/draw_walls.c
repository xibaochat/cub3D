#include "cub3D.h"

void draw_walls(void *mlx_ptr, void *win_ptr, t_map *rVar)
{
	int	x;

	x = -1;
	while (++x < WIDTH)
	{
		reset_rayon_var(rVar, x);
		calculate_side_dist(rVar);
		find_hits(rVar, x);
		calculate_start_end_point(rVar);
		draw_ceil(x, rVar);
		put_pixel(x, rVar);
		rVar->spr_buffer[x] = rVar->perpWallDist;
	}
}
