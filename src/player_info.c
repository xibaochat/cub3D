/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:19:14 by xinwang           #+#    #+#             */
/*   Updated: 2020/04/20 08:09:50 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_player_dir_plan_if_dir_is_n_or_s(char c, t_map *rvar)
{
	rvar->planeX = 0;
	rvar->planeY = 0.66;
	if (c == 'N')
	{
		rvar->dirX = 1;
		rvar->dirY = 0;
		rvar->planeX = 0;
		rvar->planeY = -0.66;
	}
	else if (c == 'S')
	{
		rvar->dirX = -1;
		rvar->dirY = 0;
	}
}

static void	init_player_dir_plan_if_dir_is_w_or_e(char c, t_map *rvar)
{
	rvar->planeX = 0.66;
	rvar->planeY = 0;
	if (c == 'W')
	{
		rvar->dirX = 0;
		rvar->dirY = 1;
	}
	else if (c == 'E')
	{
		rvar->dirX = 0;
		rvar->dirY = -1;
		rvar->planeX = -0.66;
		rvar->planeY = 0;
	}
}

void		init_player_dir(char c, t_map *rvar)
{
	rvar->player_dir = c;
	if (c == 'N' || c == 'S')
		init_player_dir_plan_if_dir_is_n_or_s(c, rvar);
	if (c == 'W' || c == 'E')
		init_player_dir_plan_if_dir_is_w_or_e(c, rvar);
}

static void	get_player_start_pos(int i, int j, char c, t_map *rvar)
{
	init_player_dir(c, rvar);
	rvar->posX = (double)i;
	rvar->posY = (double)j;
	rvar->new_posX = (double)i;
	rvar->new_posY = (double)j;
	return ;
}

void		get_player_pos(t_map *rvar)
{
	int		j;
	int		k;
	char	c;
	int		i;

	i = 0;
	j = 0;
	k = -1;
	while (rvar->map_str[++k])
	{
		c = rvar->map_str[k];
		if (is_dir_mark(c))
			return (get_player_start_pos(i, j, c, rvar));
		if (ft_isdigit(c))
			j++;
		if (c == '\n')
		{
			j = 0;
			i++;
		}
	}
}
