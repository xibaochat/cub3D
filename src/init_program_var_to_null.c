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
	r->win_ptr = NULL;
	r->mlx_ptr = NULL;
	r->map_str = NULL;
	r->map = NULL;
	r->spr_buffer = NULL;
	r->textures = NULL;
	r->hitpoint_img = NULL;
	r->bad_cat = NULL;
	r->roll_cat = NULL;
	r->door = NULL;
	r->weaps = NULL;
	r->all_spr = NULL;
	r->sprite_order = NULL;
}
