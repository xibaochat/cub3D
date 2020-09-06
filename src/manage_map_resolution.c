/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 01:23:41 by xinwang           #+#    #+#             */
/*   Updated: 2020/04/19 10:51:56 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_resolution_validity(t_map *r)
{
	int max_w;
	int max_h;

	if ((r->width) < MIN_VALID_WIDTH ||
		(r->height) < MIN_VALID_HEIGHT)
	{
		r->width = 640;
		r->height = 480;
		return ;
	}
	mlx_get_screen_size(r->mlx_ptr, &max_w, &max_h);
	if ((r->width) > max_w ||
		(r->height) > max_w)

	{
		r->width = max_w;
		r->height = max_h;
	}
}

void	get_map_taille(t_map *rvar, char *line)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	rvar->width = atoi_with_index(line, &i, &j);
	rvar->height = atoi_with_index(line, &i, &j);
	atoi_with_index(line, &i, &j);
	if (j > 2)
	{
		free_str(line);
		free_program_var(rvar, \
		"Map size is wrong\n", NULL);
	}
	rvar->resolution = 1;
	check_resolution_validity(rvar);
}

int		is_resolution_id(t_map *r, char *line)
{
	int	i;

	i = 0;
	if (line[0] != 'R')
		return (0);
	i++;
	while (line[i])
	{
		if (is_space(line[i])|| ft_isdigit(line[i]))
			i++;
		else
		{
			free_str(line);
			free_program_var(r, "Wrong Map\n", NULL);
		}
		return (1);
	}
}

void	validate_all_id_are_set(t_map *rvar)
{
	if (!rvar->no || !rvar->so || !rvar->we
		|| !rvar->ea || !rvar->s
		|| !rvar->f)
		free_program_var(rvar, \
		"Some texture path in the map is unmarkable\n", NULL);
}
