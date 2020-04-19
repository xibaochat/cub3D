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

#include "cub3D.h"

static void	get_ns_texture_path(char *s, char *path, t_map *rvar)
{
	if (!ft_strcmp(s, "NO"))
	{
		if (!rvar->NO)
			rvar->NO = path;
		else
			free_program_var(rvar, \
		"NO path ", "is defined more than one time\n");
	}
	else if (!ft_strcmp(s, "SO"))
	{
		if (!rvar->SO)
			rvar->SO = path;
		else
			free_program_var(rvar, "SO path ", \
	"is defined more than one time\n");
	}
}

static void	get_wa_texture_path(char *s, char *path, t_map *rvar)
{
	if (!ft_strcmp(s, "WE"))
	{
		if (!rvar->WE)
			rvar->WE = path;
		else
			free_program_var(rvar, "WE path ", \
		"is defined more than one time\n");
	}
	else if (!ft_strcmp(s, "EA"))
	{
		if (!rvar->EA)
			rvar->EA = path;
		else
			free_program_var(rvar, "EA path ", \
		"is defined more than one time\n");
	}
}

static void	get_sprite_floor_tex_path(char *s, char *path, t_map *rvar)
{
	if (!ft_strcmp(s, "S"))
	{
		if (!rvar->S)
			rvar->S = path;
		else
			free_program_var(rvar, "S path ", \
		"is defined more than one time\n");
	}
	else if (!ft_strcmp(s, "F"))
	{
		if (!rvar->F)
			rvar->F = path;
		else
			free_program_var(rvar, "F path ", \
		"is defined more than one time\n");
	}
}

void		get_all_texture_path(char *s, char *path, t_map *rvar)
{
	get_ns_texture_path(s, path, rvar);
	get_wa_texture_path(s, path, rvar);
	get_sprite_floor_tex_path(s, path, rvar);
}
