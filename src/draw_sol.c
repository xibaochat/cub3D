/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 01:24:44 by xinwang           #+#    #+#             */
/*   Updated: 2020/04/20 18:36:45 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		init_tex_raycasting(t_map *r, int y)
{
	r->ray_dir_x0 = r->dir_x - r->plane_x;
	r->ray_dir_y0 = r->dir_y - r->plane_y;
	r->ray_dir_x1 = r->dir_x + r->plane_x;
	r->ray_dir_y1 = r->dir_y + r->plane_y;
	r->p = y - r->height / 2;
	r->pos_z = 0.5 * r->height;
	r->row_distance = r->pos_z / r->p;
	r->floor_step_x = r->row_distance * \
	(r->ray_dir_x1 - r->ray_dir_x0) / r->width;
	r->floor_step_y = r->row_distance * \
	(r->ray_dir_y1 - r->ray_dir_y0) / r->width;
	r->floor_x = r->pos_x + r->row_distance * r->ray_dir_x0;
	r->floor_y = r->pos_y + r->row_distance * r->ray_dir_y0;
}

static void		init_tex_raycasting_x_cor(t_map *r)
{
	r->cell_x = (int)(r->floor_x);
	r->cell_y = (int)(r->floor_y);
	r->tx = (int)(r->width_floor * \
	(r->floor_x - r->cell_x)) & (r->width_floor - 1);
	r->ty = (int)(r->height_floor * (r->floor_y - r->cell_y)) \
	& (r->height_floor - 1);
	r->floor_x += r->floor_step_x;
	r->floor_y += r->floor_step_y;
}

void			draw_floor(t_map *r)
{
	int				j;
	int				y;
	int				x;
	int				k;

	y = r->height / 2;
	j = 0;
	while (y++ < r->height - 1)
	{
		init_tex_raycasting(r, y);
		x = 0;
		while (x++ < r->width - 1)
		{
			init_tex_raycasting_x_cor(r);
			k = r->width_floor * (r->ty) * (r->floor_bpp / 8) \
			+ r->tx * (r->floor_bpp / 8);
			j = (y * r->size_line) + (x * (r->bpp / 8));
			replace_pixel_value_floor(r, r->floor_texture, j, k);
		}
	}
}
