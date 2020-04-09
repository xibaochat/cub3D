#include "cub3D.h"

static int	click_to_enter(int mouse_code, int x, int y, t_map *rVar)
{
    if (mouse_code > 0)
    {
		mlx_destroy_window (rVar->mlx_ptr, rVar->win_ptr );
		start(rVar);
	}
    return 0;
}

int close_red_button(t_map *rVar, void *param)
{
    system("pkill -9 afplay");
	free_program_var(rVar, "The program is closed\n", NULL);
	return (-1);
}

static int	funct(int keycode, t_map *rVar)
{
    if (keycode == 36)
    {
		mlx_destroy_window (rVar->mlx_ptr, rVar->win_ptr );
        start(rVar);
    }
    if (keycode == 53)
    {
        system("pkill -9 afplay");
		free_program_var(rVar, "The program is closed\n", NULL);
    }
    return 0;
}

void	show_cover_menu(t_map *rVar)
{
    int		w;
    int		h;
    void	*cover_img;

    if (!(rVar->win_ptr = mlx_new_window(rVar->mlx_ptr, 1280, 720, "CAT BATTLE")))
		free_program_var(rVar, "Malloc fail in creating window", NULL);
    cover_img = mlx_xpm_file_to_image(rVar->mlx_ptr, "textures/cat_menu.xpm", &w, &h);
	mlx_put_image_to_window(rVar->mlx_ptr, rVar->win_ptr, cover_img, 0, 0);
    mlx_key_hook(rVar->win_ptr, funct, rVar);
    mlx_mouse_hook(rVar->win_ptr, click_to_enter, rVar);
    mlx_hook(rVar->win_ptr, 17, (1L << 0), close_red_button, rVar);
    mlx_loop(rVar->mlx_ptr);
}
