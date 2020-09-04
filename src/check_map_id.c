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

void	map_info_id_validity(t_map *r, char *s)
{
	if (ft_strcmp(s, "SO") && ft_strcmp(s, "WE")
		&& ft_strcmp(s, "NO") && ft_strcmp(s, "EA")
		&& ft_strcmp(s, "S")
		&& ft_strcmp(s, "F") && ft_strcmp(s, "C"))
	{
		free_str(s);
		free_program_var(r, "Map info identifier is invalid\n", NULL);
	}
}

int		map_info_id_all_get(t_map *r)
{
	if (r->so && r->we && r->no && r->ea
		&& r->width && r->height
		&& r->s && r->f && r->c)
		return (1);
//	free_program_var(r,										\
	"Some texture path in the map is unmarkable\n", NULL);
	return (0);
}
