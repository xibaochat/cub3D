#include "cub3D.h"

void change_left_rotation_dir(t_map *rVar)
{
	char c;
	char d;

	c = rVar->player_dir;
	if (c == 'E')
		d = 'N';
	else if (c == 'N')
		d = 'W';
	else if (c == 'W')
		d = 'S';
	else if (c == 'S')
		d = 'E';
	init_player_dir(d, rVar);
}

void change_right_rotation_dir(t_map *rVar)
{
	char c;
	char d;

	c = rVar->player_dir;
	if (c == 'E')
		d = 'S';
	else if (c == 'N')
		d = 'E';
	else if (c == 'W')
		d = 'N';
	else if (c == 'S')
		d = 'W';
	init_player_dir(d, rVar);
}
