/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:54:56 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 14:36:45 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		floor_color_is_number(char *line)
{
	int	i;

	i = 1;
	while (line[i])
	{
		if (is_space(line[i]) || ft_isdigit(line[i])
			|| line[i] == ',')
			i++;
		else
			return (0);
	}
	return (1);
}

int		is_floor_id(char *line)
{
	if (line[0] != 'F')
		return (0);
	return (1);
}
