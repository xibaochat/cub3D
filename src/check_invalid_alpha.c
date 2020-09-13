/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 09:09:40 by osshit            #+#    #+#             */
/*   Updated: 2020/04/19 09:47:39 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_invalid_alpha(t_map *rvar, char *str, int *mark)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[0] == '\0')
			{
				free_str(str);
				free_program_var(rvar, "Empty line in the map content\n", NULL);
			}
			if (is_dir_mark(str[i]))
				(*mark)++;
			else if (ft_isalpha(str[i]) && !is_dir_mark(str[i]))
				free_program_var(rvar, "invalid elem in the Map\n",\
				"Only space, num and alpha: W N E A are accepted\n");
			i++;
		}
	}
}
