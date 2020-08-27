/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cat_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 10:19:29 by osshit            #+#    #+#             */
/*   Updated: 2020/04/18 10:19:58 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_cat_img(t_map *rvar)
{
	int w;
	int h;

	rvar->cat_img = mlx_xpm_file_to_image(rvar->mlx_ptr, \
	"./textures/cat.xpm", &w, &h);
}
