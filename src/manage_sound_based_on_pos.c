#include "cub3D.h"

void manage_sound_based_on_pos(t_map *rVar)
{
	if (rVar->map[(int)rVar->new_posX][(int)rVar->new_posY] == 3)
		system("afplay ./sounds/miao.mp3 &");
	else if (rVar->map[(int)rVar->new_posX][(int)rVar->new_posY] == 4)
		system("afplay ./sounds/badcat_miao.mp3 &");
	else if (rVar->map[(int)rVar->new_posX][(int)rVar->new_posY] == 5)
		system("afplay ./sounds/rollcat.mp3 &");
	else if (rVar->map[(int)rVar->new_posX][(int)rVar->new_posY + 3] == 6)
		system("afplay ./sounds/guzheng.mp3 &");
}
