/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:38:58 by xinwang           #+#    #+#             */
/*   Updated: 2020/04/06 06:06:40 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	set_start_index(t_map *r, char *str, int *i, char c)
{
	if (c == 'r')
	{
		while (str[*i] && is_space(str[*i]))
			(*i)++;
		if (!ft_isdigit(str[*i]))
			free_program_var(r, "Wrong color format\n", NULL);
	}
	else if (c == 'g' || c == 'b')
	{
		if (str[*i] == ',')
		{
			(*i)++;
			while (is_space(str[*i]))
				(*i)++;
			if (!ft_isdigit(str[*i]))
				free_program_var(r, "Wrong color format\n", NULL);
		}
		else
			free_program_var(r, "Wrong color format\n", NULL);
	}
	return ;
}

int			calculation_color(t_map *r, char *str, int *i, char c)
{
	int	res;

	res = 0;
	set_start_index(r, str, i, c);
	while (str[*i] && str[*i] != ',')
	{
		if (ft_isdigit(str[*i]))
			res = res * 10 + (str[*i] - '0');
		else
			free_program_var(r, "invalid red color", NULL);
		(*i)++;
	}
	if (res > 255)
		free_program_var(r, "Color is wrong range\n", NULL);
	return (res);
}

void	get_ceil_color(t_map *r, char *path)
{
	int	i;

	i = 1;
	r->ceil_color.r = calculation_color(r, path, &i, 'r');
	r->ceil_color.g = calculation_color(r, path, &i, 'g');
	r->ceil_color.b = calculation_color(r, path, &i, 'b');
	if (path && path[i])
		free_program_var(r,\
		"The ceil color format is invalid\n", NULL);
	r->ceil_has_color = 1;
}

void	get_floor_color(t_map *r, char *path)
{
	int	i;

	i = 1;
	r->floor_color.r = calculation_color(r, path, &i, 'r');
	r->floor_color.g = calculation_color(r, path, &i, 'g');
	r->floor_color.b = calculation_color(r, path, &i, 'b');
	if (path && path[i])
		free_program_var(r,\
		"The floor color format is invalid\n", NULL);
	r->f_has_color = 1;
}
