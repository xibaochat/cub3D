/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_major_var.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 10:29:05 by osshit            #+#    #+#             */
/*   Updated: 2020/04/18 10:38:03 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	init_all_textures(t_map *rvar)
{
	init_wall_tex_info(rvar);
	init_hud_imgs(rvar);
	init_turns_img(rvar);
	init_hitpoint_imgs(rvar);
	init_cat_img(rvar);
	init_bad_cat(rvar);
	init_roll_cat(rvar);
	init_door(rvar);
	init_weapons(rvar);
	init_all_sprites(rvar);
}

void		init_all_path_and_ind_spr_value(t_map *rvar)
{
	if (rvar->round)
	{
		system("pkill -9 afplay");
		system("afplay ./sounds/game.mp3 &");
	}
	rvar->rot_speed = ROT_SPEED;
	rvar->open_up = 0;
	rvar->open_down = 0;
	rvar->open_left = 0;
	rvar->open_right = 0;
	get_player_pos(rvar);
	if (!(rvar->spr_buffer = (float *)malloc(sizeof(int) * (rvar->width))))
		free_program_var(rvar, "Malloc failed in spr_buffer", NULL);
	init_enemy_die(rvar);
	init_all_textures(rvar);
}
