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

void	extract_map_as_str(char **line, t_map *r)
{
	get_map_as_str(r, *line);
	get_next_line(-42, line);
	return ;
}

void	get_map_size_tex_dir_path(char *line, t_map *r)
{
	if (!r->resolution && is_resolution_id(r, line))
		get_map_taille(r, line);
	else if (!r->ceil_has_color && is_ceil_id(r, line))
		get_ceil_color(r, line);
	else if (!r->f_has_color && is_floor_id(r, line) &&
			 floor_color_is_number(r, line))
		get_floor_color(r, line);
	else
		get_tex_dir_path(line, r);
}

void	free_value(int value, t_map *r)
{
	if (!value)
		free_program_var(r, "The map is empty\n", NULL);

}
