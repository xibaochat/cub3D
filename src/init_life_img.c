/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_life_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 14:25:09 by xinwang           #+#    #+#             */
/*   Updated: 2020/04/17 14:27:01 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_turns_img(t_map *r)
{
	int	w;
	int	h;

	r->turns_img = mlx_xpm_file_to_image(r->mlx_ptr,\
	"./textures/heart.xpm", &w, &h);
}
