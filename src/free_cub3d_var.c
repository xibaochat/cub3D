#include "cub3D.h"

void ft_error(char  *str, char *s)
{

	if (str && ft_strcmp(str, "The program is closed\n")
		&& ft_strcmp(str, "Sorry :(\n") && ft_strcmp(str, "BMP file is saved\n"))
		ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
    if (s)
        ft_putstr_fd(s, 2);
	if (str || s)
		exit(-1);
}

static void free_texture_path(t_map *rVar)
{
	if (rVar->NO)
		free(rVar->NO);
	if (rVar->SO)
		free(rVar->SO);
	if (rVar->WE)
		free(rVar->WE);
	if (rVar->EA)
		free( rVar->EA);
	if (rVar->S)
		free(rVar->S);
	if (rVar->F)
		free(rVar->F);
	if (rVar->C)
		free(rVar->C);
}

static void free_map(t_map *rVar)
{
	int i;

	i = -1;
	if (rVar->map)
	{
		while (++i < rVar->line)
		{
			if (rVar->map[i])
			{
				free(rVar->map[i]);
				rVar->map[i] = NULL;
			}
		}
		free(rVar->map);
		rVar->map = NULL;
	}
}

static void free_wall_texture(t_map *rVar)
{
	int	i;

	i = -1;
	if (rVar->textures)
	{
		free(rVar->textures);
		rVar->textures = NULL;
	}
}

void free_program_var(t_map *rVar, char *s1, char *s2)
{
	if (rVar->win_ptr && rVar->mlx_ptr)
	{
		mlx_clear_window(rVar->mlx_ptr, rVar->win_ptr);
		mlx_destroy_window(rVar->mlx_ptr, rVar->win_ptr);
	}
	if (rVar->map_str)
	{
		free(rVar->map_str);
		rVar->map_str = NULL;
	}
	free_texture_path(rVar);
	free_map(rVar);
	if (rVar->spr_buffer)
		free(rVar->spr_buffer);
	free_wall_texture(rVar);
	free_hitpoint(rVar);
	free_spr_img(rVar);
	if (rVar->round == 0)
		ft_error(s1, s2);
	else
		final_message(s1, s2);
}
