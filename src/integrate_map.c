/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integrate_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 10:16:26 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 18:48:51 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		init_r_tex_path(t_map *r)
{
	r->no = NULL;
	r->so = NULL;
	r->we = NULL;
	r->ea = NULL;
	r->s = NULL;
	r->f = NULL;
	r->c = NULL;
}

static void	cpy_column(int **map, int i, int *k, t_map *r)
{
	int	j;

	j = 0;
	while (j < r->column)
	{
		if (ft_isdigit(r->map_str[*k]))
		{
			map[i][j++] = r->map_str[*k] - '0';
		}
		else if (r->map_str[*k] == 'N' || r->map_str[*k] == 'S' ||
				r->map_str[*k] == 'W' || r->map_str[*k] == 'E')
		{
			r->player_dir = r->map_str[*k];
			map[i][j++] = 0;
		}
		(*k)++;
	}
}

void		integrate_map(t_map *r)
{
	int i;
	int k;

	i = -1;
	k = 0;
	if (!(r->map = (int **)malloc(sizeof(int *) * (r->line))))
	{
		free_program_var(r, "malloc fail:", "r->map");
		return ;
	}
	i = -1;
	while (++i < r->line)
		r->map[i] = NULL;
	i = -1;
	while (++i < r->line)
	{
		if (!(r->map[i] = (int *)malloc(sizeof(int) * (r->column))))
			free_program_var(r, "malloc fail:", "r->map[i]");
		cpy_column(r->map, i, &k, r);
		if (r->map_str[k] && r->map_str[k] == '\n')
			k++;
	}
}

void		get_info_from_map(t_map *r)
{
	char	*line;
	int		value;

	line = NULL;
	while ((value = get_next_line(r->fd, &line)) > 0)
	{
		if (line && line[0])
		{
			//check_space_before_id(r, line);
			get_remove_space_str(&line);
			if (ft_isdigit(line[0]))
			{
				get_map_as_str(r, line);
				get_next_line(-42, &line);
				break ;
			}
			if (is_resolution_id(line))
				get_map_taille(r, line);
			else
				get_tex_dir_path(line, r);
		}
		free_str(line);
	}
	if (!value)
		free_program_var(r, "The map is empty\n", NULL);
}

void		get_final_map(t_map *r, char *file)
{
	map_is_readable(r, file);
	init_r_tex_path(r);
	get_info_from_map(r);
	valid_map_on_everyline(r, ft_strclone(r->map_str));
	validate_all_id_are_set(r);
	get_line(r, r->map_str);
	get_column(r, r->map_str);
	integrate_map(r);
}
