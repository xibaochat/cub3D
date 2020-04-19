/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 01:23:41 by xinwang           #+#    #+#             */
/*   Updated: 2020/04/18 10:52:44 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_resolution_validity(t_map	*rvar)
{
	if (WIDTH < MIN_VALID_WIDTH || WIDTH > MAX_VALID_WIDTH ||
		HEIGHT < MIN_VALID_HEIGHT || HEIGHT > MAX_VALID_HEIGHT)
		free_program_var(rvar, "Resolution value is invalid", NULL);
}

void	get_map_taille(t_map *rvar, char *line)
{
	int	i;

	i = 1;
	while (line[i] && is_space(line[i]))
		++i;
	WIDTH = atoi_with_index(line, &i);
	HEIGHT = atoi_with_index(line, &i);
	check_resolution_validity(rvar);
}

int		is_resolution_id(char *line)
{
	if (!line || !line[0] || line[0] != 'R')
		return (0);
	if (line[0] == 'R' && line[1] && is_space(line[1]))
		return(1);
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
	if (!rvar->NO || !rvar->SO || !rvar->WE
		|| !rvar->EA || !rvar->S
		|| !rvar->C || !rvar->F)
		free_program_var(rvar, "Some texture path in the map is unmarkable\n", NULL);
}
