/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cub3d_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:25:53 by osshit            #+#    #+#             */
/*   Updated: 2020/04/19 08:02:35 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	free_texture_path(t_map *rvar)
{
	if (rvar->NO)
		free(rvar->NO);
	if (rvar->SO)
		free(rvar->SO);
	if (rvar->WE)
		free(rvar->WE);
	if (rvar->EA)
		free(rvar->EA);
	if (rvar->S)
		free(rvar->S);
	if (rvar->F)
		free(rvar->F);
	if (rvar->C)
		free(rvar->C);
}

static void	free_map(t_map *rvar)
{
	int i;

	i = -1;
	if (rvar->map)
	{
		while (++i < rvar->line)
		{
			if (rvar->map[i])
			{
				free(rvar->map[i]);
				rvar->map[i] = NULL;
			}
		}
		free(rvar->map);
		rvar->map = NULL;
	}
}

static void	free_wall_texture(t_map *rvar)
{
	int	i;

	i = -1;
	if (rvar->textures)
	{
		free(rvar->textures);
		rvar->textures = NULL;
	}
}

void free_secret_door(t_map *r)
{
	int	i;

	i = -1;
	if (r->door)
	{
		while (++i < 5)
			if (r->door[i].path)
				free(r->door[i].path);
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
	}
	if (rvar->map_str)
	{
		free(rvar->map_str);
		rvar->map_str = NULL;
	}
	free_texture_path(rvar);
	free_map(rvar);
	if (rvar->spr_buffer)
		free(rvar->spr_buffer);
	free_wall_texture(rvar);
	free_hitpoint(rvar);
	free_spr_img(rvar);
	free_secret_door(rvar);
	if (rvar->round == 0)
		ft_error(s1, s2);
	else
		final_message(s1, s2);
}
