#include "cub3D.h"

static void init_img_to_draw(t_map *rVar)
{
	rVar->image_ptr = mlx_new_image(rVar->mlx_ptr, WIDTH, HEIGHT);
	rVar->addr  = mlx_get_data_addr(rVar->image_ptr, &(rVar->bpp),
									&(rVar->size_line), &(rVar->endian));
}

static void put_drawed_img_to_win(t_map *rVar)
{

	mlx_put_image_to_window(rVar->mlx_ptr, rVar->win_ptr, rVar->image_ptr, 0, 0);
	put_score_to_window(rVar);
	put_lucky_value_to_window(rVar);
	put_weapon_to_win(rVar);
	mlx_put_image_to_window(rVar->mlx_ptr, rVar->win_ptr, rVar->cat_img, 200, HEIGHT - 25);

}

void new_graph(t_map *rVar)
{
	if (rVar->hitpoint <= 0)
		game_over(rVar);
	if (rVar->round && rVar->score >= 300 && rVar->lucky_value == (rVar->all_spr + 3)->nb_occur)
		nice_job(rVar);
	else
	{
		init_img_to_draw(rVar);
		set_curr_sprites_tex(rVar);
		init_enemy_die(rVar);
		draw_floor(rVar);
		draw_walls(rVar->mlx_ptr, rVar->win_ptr, rVar);
		draw_sprites(rVar);
		if (rVar->save_bmp)
			write_bmp(rVar);
		put_drawed_img_to_win(rVar);
		change_sprite_tex_index(rVar);
	}
}
