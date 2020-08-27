/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_calculation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 07:50:01 by osshit            #+#    #+#             */
/*   Updated: 2020/04/18 11:58:49 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		cal_nb_obj(char *map_str, int i)
{
	int j;
	int nb;

	nb = 0;
	j = -1;
	while (map_str[++j])
	{
		if (map_str[j] == (i + 2) + '0')
			nb++;
	}
	return (nb);
}

void	get_indi_sprite_coord(t_spr *spr, t_map *rvar, int n)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = 0;
	while (++i < rvar->line)
	{
		j = -1;
		while (++j < rvar->column)
		{
			if (rvar->map[i][j] == n)
			{
				spr[k].x = i + 0.5;
				spr[k].y = j + 0.5;
				spr[k].x_map = i;
				spr[k].y_map = j;
				k++;
			}
		}
	}
}

void	init_hp(t_prop *spr)
{
	int i;

	i = -1;
	while (++i < spr->nb_occur)
		spr->indi_spr[i].hitpoint = 100;
}

void	init_origin_sprite(t_prop *spr)
{
	int i;

	i = -1;
	while (++i < spr->nb_occur)
		spr->indi_spr[i].origin_sprite = spr;
}
