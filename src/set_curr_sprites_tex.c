/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_curr_sprites_tex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 08:12:14 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 08:12:32 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_curr_sprites_tex(t_map *rvar)
{
	int	i;
	int	j;

	i = -1;
	while (++i < NB_SPRITE)
	{
		j = rvar->all_spr[i].nb_occur;
		if (i < NB_SPRITE - 1)
			set_sprite_img(rvar, rvar->all_spr + i, i);
		if (i == NB_SPRITE - 1)
			init_mutan_img(rvar);
	}
}
