/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_elem_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 20:43:15 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 18:47:38 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*extract_path_from_line(t_map *r, char *line, int i)
{
	char	*path;

	path = NULL;
	while (line[i] && is_space(line[i]))
		i++;
	if (!(path = ft_strnew(ft_strlen(line) - i + 1)))
	{
		free_str(line);
		free_program_var(r, "malloc texture path process failed", NULL);
	}
	ft_strcat(path, line + i);
	return (path);
}

char	*get_wall_texture_id_path(char *line, t_map *r)
{
	get_north_texture_path(line, r);
	get_south_texture_path(line, r);
	get_west_texture_path(line, r);
	get_east_texture_path(line, r);
}

void		get_tex_dir_path(char *line, t_map *r)
{
	if (is_wall_texture_id(line, r))
		get_wall_texture_id_path(line, r);
	else if (line[0] == 'F' && !r->f_has_color && !r->f)
		r->f = extract_path_from_line(r, line, 1);
	else if (line[0] == 'S' && !r->s)
		r->s = extract_path_from_line(r, line, 1);
	else
		free_program_var(r, "Wrong map element\n", NULL);
}
