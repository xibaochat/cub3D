/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hitpoint_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 10:15:54 by osshit            #+#    #+#             */
/*   Updated: 2020/04/19 10:15:56 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_hitpoint_imgs(t_map *r)
{
	int	w;
	int	h;

	r->hitpoint_img = (void **)malloc(sizeof(void *) * 4);
	r->hitpoint_img[0] = mlx_xpm_file_to_image(r->mlx_ptr,\
	"./textures/hitpoint.xpm", &w, &h);
	r->hitpoint_img[1] = mlx_xpm_file_to_image(r->mlx_ptr, \
	"./textures/hitpoint01.xpm", &w, &h);
	r->hitpoint_img[2] = mlx_xpm_file_to_image(r->mlx_ptr, \
	"./textures/hitpoint02.xpm", &w, &h);
	r->hitpoint_img[3] = mlx_xpm_file_to_image(r->mlx_ptr, \
	"./textures/hitpoint03.xpm", &w, &h);
}
