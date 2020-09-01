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

	i = 1;
	while (line[i] && is_space(line[i]))
		++i;
	rvar->width = atoi_with_index(line, &i);
	rvar->height = atoi_with_index(line, &i);
	check_resolution_validity(rvar);
}

int		is_resolution_id(char *line)
{
	if (!line || !line[0] || line[0] != 'R')
		return (0);
	if (line[0] == 'R' && line[1] && is_space(line[1]))
		return (1);
	return (0);
}

void	check_space_before_id(t_map *rvar, char *line)
{
	int	i;

	i = 0;
	while (line[i] && is_space(line[i]))
		i++;
	if (i > 0)
		free_program_var(rvar, "Space before identifier.", NULL);
}

void	validate_all_id_are_set(t_map *rvar)
{
	if (!rvar->no || !rvar->so || !rvar->we
		|| !rvar->ea || !rvar->s
		|| !rvar->c || !rvar->f)
		free_program_var(rvar, \
		"Some texture path in the map is unmarkable\n", NULL);
}
