/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_program_var_to_null.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 09:24:23 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 09:25:09 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_program_var(t_map *r)
{
	r->sprite_distance = NULL;
	r->door = NULL;
	r->textures = NULL;
	r->roll_cat = NULL;
	r->bad_cat = NULL;
	r->hitpoint_img = NULL;
	r->all_spr = NULL;
	r->weaps = NULL;
	r->mutant = NULL;
	r->cat_img = NULL;
	r->cats = NULL;
	r->cat_buffer = NULL;
	r->turns_img = NULL;
	r->weapon_img = NULL;
	r->score_img = NULL;
	r->spr = NULL;
	r->spr_buffer = NULL;
	r->spr_img_ptr = NULL;
	r->spr_tex = NULL;
	r->mlx_ptr = NULL;
	r->win_ptr = NULL;
	r->image_ptr = NULL;
	r->addr = NULL;
	r->map = NULL;
	r->no = NULL;
	r->so = NULL;
	r->we = NULL;
	r->ea = NULL;
	r->s = NULL;
	r->map_str = NULL;
	r->text_img_ptr = NULL;
	r->texture = NULL;
	r->screen_img = NULL;
	r->floor_img_ptr = NULL;
	r->floor_texture = NULL;
	r->f = NULL;
	r->c = NULL;
	r->sprite_order = NULL;
}
