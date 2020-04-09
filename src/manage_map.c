/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 01:23:41 by xinwang           #+#    #+#             */
/*   Updated: 2020/04/07 02:12:46 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*void print_map(int **map, char *map_str)
{
	int i;
	int j;
	int line;
	int column;

	line = get_line(map_str);
	column = get_column(map_str);
	i  = -1;
	j = -1;
	while (++i < line + 1)
	{
		j = -1;
		while (++j < column + 1)
			printf("%d ", map[i][j]);
		printf("\n");
	}
	}*/

void	check_resolution_validity(t_map	*rVar)
{
	if (WIDTH < MIN_VALID_WIDTH || WIDTH > MAX_VALID_WIDTH ||
		HEIGHT < MIN_VALID_HEIGHT || HEIGHT > MAX_VALID_HEIGHT)
		free_program_var(rVar, "Resolution value is invalid", NULL);
}

void	get_map_taille(t_map *rVar, char *line)
{
	int	i;

	i = 1;
	while (line[i] && is_space(line[i]))
		++i;
	WIDTH = atoi_with_index(line, &i);
	HEIGHT = atoi_with_index(line, &i);
	check_resolution_validity(rVar);
}

int		is_resolution_id(char *line)
{
	if (!line || !line[0] || line[0] != 'R')
		return (0);
	if (line[0] == 'R' && line[1] && is_space(line[1]))
		return(1);
	return (0);
}

void	check_space_before_id(t_map *rVar, char *line)
{
	int	i;

	i = 0;
    while (line[i] && is_space(line[i]))
        i++;
    if (i > 0)
        free_program_var(rVar, "Space before identifier.", NULL);
}

void	validate_all_id_are_set(t_map *rVar)
{
	if (!rVar->NO || !rVar->SO || !rVar->WE
		|| !rVar->EA || !rVar->S
		|| !rVar->C || !rVar->F)
		free_program_var(rVar, "Some texture path in the map is unmarkable\n", NULL);
}
