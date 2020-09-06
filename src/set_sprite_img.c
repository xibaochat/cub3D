/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprite_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:39:40 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 19:49:16 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void validate_texture_exist(t_map *rvar, char *tex)
{
	int	fd;

	fd = open(tex, O_RDONLY);
	if (fd == -1)
		free_program_var(rvar, "Texture file does not exit\n", NULL);
	else
		close(fd);

}

void	set_sprite_img(t_map *rvar, t_prop *spr, int i)
{
	char	*filepath;
	int		j;

	filepath = NULL;
	j = -1;
	if (i != 5)
	{
		if (!i)
			filepath = rvar->s;
		else if (i == 1)
			filepath = "./textures/cat.xpm";
		else if (i == 2)
			filepath = rvar->bad_cat[rvar->nb_bad_cat].path;
		else if (i == 3)
			filepath = rvar->roll_cat[rvar->nb_roll_cat].path;
		else
			filepath = rvar->door[rvar->nb_door].path;
		if (spr->img)
			mlx_destroy_image(rvar->mlx_ptr, spr->img);
		validate_texture_exist(rvar, filepath);
		spr->img = mlx_xpm_file_to_image(rvar->mlx_ptr, \
		filepath, &spr->width, &spr->height);
		if (!spr->img)
			free_program_var(rvar, "Can't find the spr filepath: ", filepath);
		spr->addr = mlx_get_data_addr(spr->img, &(spr->bpp), \
		&(spr->s_l), &(spr->endian));
	}
}
