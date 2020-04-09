#include "cub3D.h"

void    put_lucky_value_to_window(t_map  *rVar)
{
	int i;

	i = -1;
	while (++i < rVar->lucky_value)
		mlx_put_image_to_window(rVar->mlx_ptr, rVar->win_ptr, rVar->turns_img, WIDTH - 35 * (i + 2), 25 * (i + 2));
}

void    put_score_to_window(t_map   *rVar)
{
    int w;
    int h;

    rVar->score_img = mlx_xpm_file_to_image(rVar->mlx_ptr, "textures/score.xpm", &w, &h);
    mlx_put_image_to_window(rVar->mlx_ptr, rVar->win_ptr, rVar->score_img, 0, HEIGHT - 25);
	mlx_string_put (rVar->mlx_ptr, rVar->win_ptr, 10, HEIGHT - 5, 15692404, ft_itoa(rVar->score));
	if (rVar->hitpoint >= 100 )
		mlx_put_image_to_window(rVar->mlx_ptr, rVar->win_ptr, rVar->hitpoint_img[0], 100, HEIGHT - 25);
	else if(rVar->hitpoint >=  50 )
		mlx_put_image_to_window(rVar->mlx_ptr, rVar->win_ptr, rVar->hitpoint_img[1], 100, HEIGHT - 25);
	else if(rVar->hitpoint >= 25 )
		mlx_put_image_to_window(rVar->mlx_ptr, rVar->win_ptr, rVar->hitpoint_img[2], 100, HEIGHT - 25);
	else if (rVar->hitpoint != 0 && rVar->hitpoint < 25)
		mlx_put_image_to_window(rVar->mlx_ptr, rVar->win_ptr, rVar->hitpoint_img[3], 100, HEIGHT - 25);

}
