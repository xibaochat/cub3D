/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fst_arg_in_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 20:43:15 by osshit            #+#    #+#             */
/*   Updated: 2020/04/06 06:17:26 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int color_is_valid(t_color color, t_map *rVar)
{
	if (color.r >= 0 && color.r <= 255
		&& color.g >= 0 && color.g <= 255
		&& color.b >= 0 && color.b <= 255 )
		return (1);
	free_program_var(rVar, "invalide ceil color range\n",	\
					 "color shoube be in range[0, 255]");
	return (-1);
}

static void	get_ceil_path(char	*path, t_map *rVar)
{
	int i;

	i = 0;
	rVar->ceil_color.r =  atoi_with_index(path, &i);
	rVar->ceil_color.g =  atoi_with_index(path, &i);
	rVar->ceil_color.b =  atoi_with_index(path, &i);
	if (color_is_valid(rVar->ceil_color, rVar))
		rVar->C = path;
}

static void free_strs(char *path, char *s)
{
	free(path);
	free(s);
	ft_error(s, "invalid value.");
}

void 	assign_tex_path(char *str, char *s, t_map *rVar, int i)
{
	char *path;

	while (str[i] && is_space(str[i]))
		i++;
	if (!(path = ft_strnew(ft_strlen(str) - i + 1)))
		free_program_var(rVar, "malloc texture path process failed", NULL);
	ft_strcat(path, str + i);
	if (ft_strcmp(s, "C") && valide_texture_path(rVar, path))
		get_all_texture_path(s, path, rVar);
	else if (!ft_strcmp(s, "C"))
	{
		if (!rVar->C)
			get_ceil_path(path, rVar);
		else
			free_program_var(rVar, "multi ceil path\n", NULL);
	}
	else
		free_strs(path, s);
}

void	get_tex_dir_path(char *line, t_map *rVar)
{
	int		i;
	char	*s;
	char	*path;

	i = 0;
	while (line[i] && !is_space(line[i]))
		i++;
	s = ft_strnew(i + 1);
	s = ft_strncat(s, line, i);
	if (!line[i])
		free_program_var(rVar, "empty texture path", NULL);
	assign_tex_path(line, s, rVar, i);
}
