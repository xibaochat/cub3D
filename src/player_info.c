/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:19:14 by xinwang           #+#    #+#             */
/*   Updated: 2020/04/07 04:44:41 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void init_player_dir_plan_if_dir_is_N_or_S(char c, t_map *rVar)
{
	rVar->planeX = 0;
	rVar->planeY = 0.66;
	if (c == 'N')
	{
		rVar->dirX = 1;
		rVar->dirY = 0;
		rVar->planeX = 0;
		rVar->planeY = -0.66;
	}
	else if (c == 'S')
	{
		rVar->dirX = -1;
		rVar->dirY = 0;
	}
}

static void init_player_dir_plan_if_dir_is_W_or_E(char c, t_map *rVar)
{
	rVar->planeX = 0.66;
	rVar->planeY = 0;
	if (c == 'W')
	{
		rVar->dirX = 0;
		rVar->dirY = 1;
	}
	else if (c == 'E')
	{
		rVar->dirX = 0;
		rVar->dirY = -1;
		rVar->planeX = -0.66;
		rVar->planeY = 0;
	}
}

void init_player_dir(char c, t_map *rVar)
{
	rVar->player_dir = c;
	if (c == 'N' || c == 'S')
		init_player_dir_plan_if_dir_is_N_or_S(c, rVar);
	if (c == 'W' || c == 'E')
		init_player_dir_plan_if_dir_is_W_or_E(c, rVar);
}

static void get_player_start_pos(int i, int j, char c, t_map	*rVar)
{
	init_player_dir(c, rVar);
	rVar->posX = (double)i;
	rVar->posY = (double)j;
	rVar->new_posX = (double)i;
	rVar->new_posY = (double)j;
	return ;
}


void get_player_pos(t_map *rVar)
{
	int j;
	int k;
	char c;
	int i;

	i = 0;
	j = 0;
	k = -1;
	while (rVar->map_str[++k])
	{
		c = rVar->map_str[k];
		if (is_dir_mark(c))
			return (get_player_start_pos(i, j, c, rVar));
		if (ft_isdigit(c))
			j++;
		if (c == '\n')
		{
			j = 0;
			i++;
		}
	}
}
