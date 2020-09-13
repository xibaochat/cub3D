/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:54:56 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 14:36:45 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_map_content(char *line)
{
	int	i;

	i = 0;
	if (!line[0])
		return (0);
	while (line[i])
	{
		if (line[i] == ' ' || (line[i] >= '0' && line[i] <= '7')
			|| is_dir_mark(line[i]))
			i++;
		else
			return (0);
	}
	return (1);
}
