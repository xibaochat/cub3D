/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_graph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 09:46:29 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 19:01:43 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	init_img_to_draw(t_map *r)
{
	if (r->image_ptr)
		mlx_destroy_image(r->mlx_ptr, r->image_ptr);
	r->image_ptr = mlx_new_image(r->mlx_ptr, r->width, r->height);
	r->addr = mlx_get_data_addr(r->image_ptr, &(r->bpp),
									&(r->size_line), &(r->endian));
}

static void	put_drawed_img_to_win(t_map *r)
{
	mlx_put_image_to_window(r->mlx_ptr, r->win_ptr, r->image_ptr, 0, 0);
	put_score_to_window(r);
	put_lucky_value_to_window(r);
	put_weapon_to_win(r);
	mlx_put_image_to_window(r->mlx_ptr, r->win_ptr, \
	r->cat_img, 200, r->height - 25);
}

void		new_graph(t_map *r)
{
	if (r->hitpoint <= 0)
		game_over(r);
	if (r->round && r->score >= 300 &&
		r->lucky_value == (r->all_spr + 3)->nb_occur)
		nice_job(r);
	else
	{
		init_img_to_draw(r);
		set_curr_sprites_tex(r);
		init_enemy_die(r);
		if (!r->f_has_color && r->f)
			draw_floor(r);
		draw_walls(r);
		draw_sprites(r);
		if (r->save_bmp)
			write_bmp(r);
		put_drawed_img_to_win(r);
		change_sprite_tex_index(r);
	}
}
