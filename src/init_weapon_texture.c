/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_weapon_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 21:56:52 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 09:51:55 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static char		*clean_strjoin(char *path, char *s1, char *s2)
{
	char *str;

	str = ft_strjoin(s1, s2);
	if (path)
		free_str(path);
	return (str);
}

static char		*get_tex_path(int i, char *weap_name)
{
	char *path;

	path = NULL;
	path = clean_strjoin(path, "./textures/weapons/", weap_name);
	path = clean_strjoin(path, path, "/texture_");
	path = clean_strjoin(path, path, ft_itoa(i));
	path = clean_strjoin(path, path, ".xpm");
	return (path);
}

void			init_weapon_texture(t_map *rvar, t_weap *weap, \
				int nb_tex, char *weapon_name)
{
	int		i;
	char	*tex_path;
	int		w;
	int		h;

	i = -1;
	tex_path = NULL;
	if (!(weap->tex = (void	**)malloc(sizeof(void	*) * nb_tex)))
		free_program_var(rvar, "Malloc fail in weap->tex\n", NULL);
	while (++i < nb_tex)
	{
		tex_path = get_tex_path(i, weapon_name);
		weap->tex[i] = mlx_xpm_file_to_image(rvar->mlx_ptr, tex_path, &w, &h);
		if (tex_path)
			free_str(tex_path);
		if (!weap->tex[i])
			free_program_var(rvar, "can't creat new img\n", NULL);
	}
}
