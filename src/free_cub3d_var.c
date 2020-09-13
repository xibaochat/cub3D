/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cub3d_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:25:53 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 11:53:25 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	free_texture_path(t_map *rvar)
{
	if (rvar->no)
		free_str(rvar->no);
	if (rvar->so)
		free_str(rvar->so);
	if (rvar->we)
		free_str(rvar->we);
	if (rvar->ea)
		free_str(rvar->ea);
	if (rvar->s)
		free_str(rvar->s);
	if (rvar->f)
		free_str(rvar->f);
}

static void	free_map(t_map *rvar)
{
	int i;

	i = -1;
	if (rvar->map)
	{
		while (++i < rvar->line)
			if (rvar->map[i])
			{
				free(rvar->map[i]);
				rvar->map[i] = NULL;
			}
		free(rvar->map);
		rvar->map = NULL;
	}
}

void		free_secret_door(t_map *r)
{
	int	i;

	i = -1;
	if (r->door)
	{
		while (++i < 5)
			if (r->door[i].path)
				free_str(r->door[i].path);
		free(r->door);
		r->door = NULL;
	}
}

void		free_program_var(t_map *rvar, char *s1, char *s2)
{
	if (rvar->win_ptr && rvar->mlx_ptr)
	{
		mlx_clear_window(rvar->mlx_ptr, rvar->win_ptr);
		mlx_destroy_window(rvar->mlx_ptr, rvar->win_ptr);
		rvar->win_ptr = NULL;
	}
	if (rvar->map_str)
		free_str(rvar->map_str);
	free_texture_path(rvar);
	free_map(rvar);
	if (rvar->spr_buffer)
	{
		free(rvar->spr_buffer);
		rvar->spr_buffer = NULL;
	}
	free_secret_door(rvar);
	ft_error(s1, s2);
}
