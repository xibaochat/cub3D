/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:21:23 by xinwang           #+#    #+#             */
/*   Updated: 2020/04/20 09:37:20 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int			wall_collision(double x, double y, int **map)
{
	return (map[(int)(x)][(int)y] != 0);
}

void		move_action(t_map *r)
{
	if (r->open_up == 1)
		move_up(r);
	if (r->open_down == 1)
		move_down(r);
	if (r->open_left == 1)
		move_left(r);
	if (r->open_right == 1)
		move_right(r);
	if (r->open_a == 1)
		move_vertical_left(r);
	if (r->open_d == 1)
		move_vertical_right(r);
}

static int	has_moved(t_map *r)
{
	return (r->open_up == 1 || r->open_down == 1 ||
			r->open_left == 1 || r->open_right == 1 ||
			r->open_a == 1 || r->open_d == 1);
}

int			movement(t_map *r)
{
	if (has_moved(r))
	{
		mlx_destroy_image(r->mlx_ptr, r->image_ptr);
		r->image_ptr = NULL;
		move_action(r);
		//manage_sound_based_on_pos(r);
		set_new_pos_and_value_after_pick_spr(r);
		inser_hurt(r, r->new_pos_x, r->new_pos_y);
	}
	new_graph(r);
	return (0);
}
