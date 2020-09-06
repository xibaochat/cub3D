/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 14:51:11 by osshit            #+#    #+#             */
/*   Updated: 2020/04/17 14:51:14 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	get_ns_texture_path(char *s, char *path, t_map *r)
{
	if (!ft_strcmp(s, "NO"))
	{
		if (!r->no)
			r->no = path;
		else
			free_program_str(r, s, path, "path defined multi times\n");

	}
	else if (!ft_strcmp(s, "SO"))
	{
		if (!r->so)
			r->so = path;
		else
			free_program_str(r, s, path, "path defined multi times\n");

	}
}

static void	get_wa_texture_path(char *s, char *path, t_map *r)
{
	if (!ft_strcmp(s, "WE"))
	{
		if (!r->we)
			r->we = path;
		else
			free_program_str(r, s, path, "path defined multi times\n");

	}
	else if (!ft_strcmp(s, "EA"))
	{
		if (!r->ea)
			r->ea = path;
		else
			free_program_str(r, s, path, "path defined multi times\n");

	}
}

static void	get_sprite_floor_tex_path(char *s, char *path, t_map *r)
{
	if (!ft_strcmp(s, "S"))
	{
		if (!r->s)
			r->s = path;
		else
			free_program_str(r, s, path, "path defined multi times\n");

	}
	else if (!ft_strcmp(s, "F"))
	{
		if (!r->f)
			r->f = path;
		else
			free_program_str(r, s, path, "path defined multi times\n");

	}
}

void		get_all_texture_path(char *s, char *path, t_map *r)
{
	get_ns_texture_path(s, path, r);
	get_wa_texture_path(s, path, r);
	get_sprite_floor_tex_path(s, path, r);
}
