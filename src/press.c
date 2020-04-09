# include "cub3D.h"

int		press(int keycode, t_map *rVar)
{
	if (keycode == COUTEAU)
		rVar->couteau = 1;
	if (keycode == SHOOTING)
		rVar->shooting = 1;
    if (keycode == ESCAPE_KEY)
    {
        system("pkill -9 afplay");
        exit(0);
    }
    if (keycode == W_KEY)
        rVar->open_up = 1;
    if (keycode == S_KEY)
        rVar->open_down = 1;
    if (keycode == A_KEY)
        rVar->open_A = 1;
    if (keycode == D_KEY)
        rVar->open_D = 1;
    if(keycode == LEFT_ARROW_KEY)
        rVar->open_left = 1;
    if (keycode == RIGHT_ARROW_KEY)
        rVar->open_right = 1;
    return (0);
}
