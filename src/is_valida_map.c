/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valida_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 09:17:49 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 09:18:22 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_is_readable(t_map *rvar, char *file)
{
	rvar->fd = open(file, O_RDONLY);
	if (rvar->fd == -1)
		ft_error("the map does not exit", NULL);
}

int		valide_texture_path(t_map *rvar, char *str)
{
	int	fd;

	fd = open(str, O_DIRECTORY);
	if (fd >= 3)
	{
		close(fd);
		free_program_var(rvar, str, ": Is a directory\n");
	}
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		free_program_var(rvar, str, ": No such file\n");
	}
	close(fd);
	return (1);
}
