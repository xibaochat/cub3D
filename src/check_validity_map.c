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

int	cal_nb_elem(char *str, int *mark)
{
	int	i;
	int	nb_elem;

	nb_elem = 0;
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || is_dir_mark(str[i]))
		{
			if (is_dir_mark(str[i]))
				(*mark)++;
			nb_elem++;
		}
		i++;
	}
	return (nb_elem);
}

int	is_all_wall(t_map *rvar, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((i % 2 == 0 && str[i] == '1')
			|| (i % 2 == 1 && str[i] == ' '))
			i++;
		else
			free_program_var(rvar, \
		"Wall in the map is not fully covered\n", NULL);
	}
	return (0);
}

int	start_end_has_wall(t_map *rvar, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(str);
	if (str[i] == '1' && str[--j] == '1')
		return (0);
	free_program_var(rvar, "wall is not around in the map\n", NULL);
	return (-1);
}

int	has_invalid_alpha(t_map *rvar, char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if ((i % 2 == 1 && str[i] == ' ') ||
			(i % 2 == 0 && (ft_isdigit(str[i]) ||
			is_dir_mark(str[i]))))
			i++;
		else
			free_program_var(rvar, "invalid elem in the Map\n",\
			"only space, num and alpha: W N E A are accepted\n");
	}
	return (0);
}
