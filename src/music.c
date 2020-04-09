#include "cub3D.h"

void	insert_warn(t_map	*rVar)
{
	if (rVar->hitpoint > 0)
		system("afplay ./sounds/damage.mp3 &");
	rVar->hitpoint -= 5;
}

void mutant_attack_sound(t_map *rVar)
{
	if (rVar->hitpoint > 0)
		system("afplay ./sounds/pig_attack.mp3 &");
	rVar->hitpoint -= 5;
}
