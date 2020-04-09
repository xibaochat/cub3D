#include "cub3D.h"

void init_program_var(t_map *rVar)
{
    rVar->win_ptr = NULL;
    rVar->mlx_ptr = NULL;
    rVar->map_str = NULL;
    rVar->map = NULL;
    rVar->spr_buffer = NULL;
    rVar->textures = NULL;
    rVar->hitpoint_img = NULL;
    rVar->bad_cat = NULL;
    rVar->roll_cat = NULL;
    rVar->door = NULL;
	rVar->weaps = NULL;
	rVar->all_spr = NULL;
	rVar->sprite_order = NULL;
}
