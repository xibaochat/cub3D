/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_key_code.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 10:17:47 by osshit            #+#    #+#             */
/*   Updated: 2020/04/19 10:18:49 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	manage_rotation_arrow(int keycode, t_map *r)
{
	if (keycode == LEFT_ARROW_KEY)
		change_left_rotation_dir(r);
	if (keycode == RIGHT_ARROW_KEY)
		change_right_rotation_dir(r);
	mlx_destroy_image(r->mlx_ptr, r->image_ptr);
	new_graph(r);
	return (0);
}
