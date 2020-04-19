#include "cub3D.h"

static void init_img_to_draw(t_map *rvar)
{
	rvar->image_ptr = mlx_new_image(rvar->mlx_ptr, WIDTH, HEIGHT);
	rvar->addr  = mlx_get_data_addr(rvar->image_ptr, &(rvar->bpp),
									&(rvar->size_line), &(rvar->endian));
}

static void put_drawed_img_to_win(t_map *rvar)
{

	mlx_put_image_to_window(rvar->mlx_ptr, rvar->win_ptr, rvar->image_ptr, 0, 0);
	put_score_to_window(rvar);
	put_lucky_value_to_window(rvar);
	put_weapon_to_win(rvar);
	mlx_put_image_to_window(rvar->mlx_ptr, rvar->win_ptr, rvar->cat_img, 200, HEIGHT - 25);

}

void new_graph(t_map *rvar)
{
	if (rvar->hitpoint <= 0)
		game_over(rvar);
	if (rvar->round && rvar->score >= 300 && rvar->lucky_value == (rvar->all_spr + 3)->nb_occur)
		nice_job(rvar);
	else
	{
		init_img_to_draw(rvar);
		set_curr_sprites_tex(rvar);
		init_enemy_die(rvar);
		draw_floor(rvar);
		draw_walls(rvar->mlx_ptr, rvar->win_ptr, rvar);
		draw_sprites(rvar);
		if (rvar->save_bmp)
			write_bmp(rvar);
		put_drawed_img_to_win(rvar);
		change_sprite_tex_index(rvar);
	}
}
