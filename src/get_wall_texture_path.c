/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_id.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 20:43:15 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 18:47:38 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_north_texture_path(char *line, t_map *r)
{
	char	*s;

	s = NULL;
	if (line[0] && line[1]
	&& line[0] == 'N' && line[1] == 'O')
	{
		if (!r->no)
		{
			s = extract_path_from_line(r, line, 2);
			if (valide_texture_path(r, s))
				r->no = s;
			else
			{
				free_str(s);
				free_str(line);
				free_program_var(r, "Wrong Map\n", "NO path multi defined\n");
			}
		}
		else
		{
			free_str(line);
			free_program_var(r, "Wrong Map\n", \
		"NO path multi defined\n");
		}
	}
}

void	get_south_texture_path(char *line, t_map *r)
{
	char	*s;

	s = NULL;
	if (line[0] && line[1] && line[0] == 'S' && line[1] == 'O')
	{
		if (!r->so)
		{
			s = extract_path_from_line(r, line, 2);
			if (valide_texture_path(r, s))
				r->so = s;
			else
			{
				free_str(s);
				free_str(line);
				free_program_var(r, "Wrong Map\n", "SO path multi defined\n");
			}
		}
		else
		{
			free_str(line);
			free_program_var(r, "Wrong Map\n",\
		"SO path multi defined\n");
		}
	}
}

void	get_west_texture_path(char *line, t_map *r)
{
	char	*s;

	s = NULL;
	if (line[0] && line[1]
	&& line[0] == 'W' && line[1] == 'E')
	{
		if (!r->we)
		{
			s = extract_path_from_line(r, line, 2);
			if (valide_texture_path(r, s))
				r->we = s;
			else
			{
				free_str(s);
				free_str(line);
				free_program_var(r, "Wrong Map\n", "EA path multi defined\n");
			}
		}
		else
		{
			free_str(line);
			free_program_var(r, "Wrong Map\n", "WE path multi defined\n");
		}
	}
}

void	get_east_texture_path(char *line, t_map *r)
{
	char	*s;

	s = NULL;
	if (line[0] && line[1]
		&& line[0] == 'E' && line[1] == 'A')
	{
		if (!r->ea)
		{
			s = extract_path_from_line(r, line, 2);
			if (valide_texture_path(r, s))
				r->ea = s;
			else
			{
				free_str(s);
				free_str(line);
				free_program_var(r, "Wrong Map\n", "EA path multi defined\n");
			}
		}
		else
		{
			free_str(line);
			free_program_var(r, "Wrong Map\n", "EA path multi defined\n");
		}
	}
}
