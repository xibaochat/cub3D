/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 06:36:39 by osshit            #+#    #+#             */
/*   Updated: 2020/04/19 06:40:09 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*get_mutant_tex_path(t_map *rvar, int j)
{
	char	*s;
	int		hitpoints;
	char	*str;

	hitpoints = rvar->all_spr[5].indi_spr[j].hitpoint;
	if (hitpoints == 100)
		rvar->all_spr[5].indi_spr[j].nb_tex = 0;
	else if (hitpoints >= 75)
		rvar->all_spr[5].indi_spr[j].nb_tex = 1;
	else if (hitpoints >= 50)
	{
		rvar->all_spr[5].indi_spr[j].nb_tex = 2;
		rvar->all_spr[5].indi_spr[j].hitpoint = 7;
	}
	else
	{
		(rvar->all_spr[5].indi_spr[j].nb_tex)++;
		(rvar->all_spr[5].indi_spr[j].hitpoint)--;
	}
	s = ft_strjoin("./textures/enemies/mutant/chest_", \
	ft_itoa(rvar->all_spr[5].indi_spr[j].nb_tex));
	str = ft_strjoin(s, ".xpm");
	free(s);
	return (str);
}

void	init_mutan_img(t_map *rvar)
{
	int		j;
	char	*tex_path;
	t_prop	*spr;

	j = -1;
	spr = rvar->all_spr + 5;
	while (++j < spr->nb_occur)
	{
		if (spr->indi_spr[j].hitpoint > 1)
		{
			tex_path = get_mutant_tex_path(rvar, j);
			spr->indi_spr[j].img = mlx_xpm_file_to_image(rvar->mlx_ptr, \
		tex_path, &spr->width, &spr->height);
			spr->indi_spr[j].addr = mlx_get_data_addr(spr->indi_spr[j].img,\
			&(spr->bpp), &(spr->s_l), &(spr->endian));
		}
		else if (spr->indi_spr[j].hitpoint == 1)
		{
			spr->indi_spr[j].hitpoint = 0;
			rvar->map[spr->indi_spr[j].x_map][spr->indi_spr[j].y_map] = 0;
			rvar->hitpoint += 25;
		}
	}
}
