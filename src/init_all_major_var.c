#include "cub3D.h"

static void init_all_textures(t_map *rVar)
{
	init_wall_tex_info(rVar);
	init_hud_imgs(rVar);
	init_turns_img(rVar);
	init_hitpoint_imgs(rVar);
	init_cat_img(rVar);
	init_bad_cat(rVar);
	init_roll_cat(rVar);
	init_door(rVar);
	init_weapons(rVar);
	init_all_sprites(rVar);
}

void	init_all_path_and_ind_spr_value(t_map *rVar)
{
	if (rVar->round)
	{
		system("pkill -9 afplay");
		system("afplay ./sounds/game.mp3 &");
	}
    rVar->rotSpeed = ROT_SPEED;
	rVar->open_up = 0;
    rVar->open_down = 0;
    rVar->open_left = 0;
    rVar->open_right = 0;
    get_player_pos(rVar);
    if (!(rVar->spr_buffer = (float *)malloc(sizeof(int) * WIDTH)))
		free_program_var(rVar, "Malloc failed in spr_buffer", NULL);
	init_enemy_die(rVar);
	init_all_textures(rVar);
}
