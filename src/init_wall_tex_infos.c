/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wall_tex_infos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 10:22:26 by osshit            #+#    #+#             */
/*   Updated: 2020/04/18 10:22:27 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static char	*get_tex_path(t_map *rvar, int i)
{
	if (!i)
		return (rvar->no);
	else if (i == 1)
		return (rvar->so);
	else if (i == 2)
		return (rvar->we);
	else
		return (rvar->ea);
}

void		init_wall_tex_info(t_map *rvar)
{
	int i;

	i = -1;
	if (!(rvar->textures = (t_texture *)malloc(sizeof(t_texture) * 4)))
		free_program_var(rvar, "Wall texture malloc failed\n", NULL);
	while (++i < 4)
	{
		rvar->textures[i].img = mlx_xpm_file_to_image(rvar->mlx_ptr, \
	get_tex_path(rvar, i), &(rvar->textures[i].w), &(rvar->textures[i].h));
		rvar->textures[i].addr = mlx_get_data_addr(rvar->textures[i].img, \
	&(rvar->bpp), &(rvar->s_l), &(rvar->endian));
	}
}
