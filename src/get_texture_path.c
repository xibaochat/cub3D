#include "cub3D.h"

static void	get_NS_texture_path(char *s, char *path, t_map *rVar)
{
	if (!ft_strcmp(s, "NO"))
	{
		if (!rVar->NO)
			rVar->NO = path;
		else
			free_program_var(rVar, "NO path ", "is defined more than one time\n");
	}
	else if (!ft_strcmp(s, "SO"))
    {
        if (!rVar->SO)
            rVar->SO = path;
        else
			free_program_var(rVar, "SO path ", "is defined more than one time\n");
    }
}

static void	get_WA_texture_path(char *s, char *path, t_map *rVar)
{
	if (!ft_strcmp(s, "WE"))
	{
		if (!rVar->WE)
			rVar->WE = path;
		else
			free_program_var(rVar, "WE path ", "is defined more than one time\n");
	}
	else if (!ft_strcmp(s, "EA"))
    {
        if (!rVar->EA)
            rVar->EA = path;
        else
			free_program_var(rVar, "EA path ", "is defined more than one time\n");
    }
}

static void	get_sprite_floor_tex_path(char	*s, char *path, t_map *rVar)
{
	if (!ft_strcmp(s, "S"))
    {
        if (!rVar->S)
            rVar->S = path;
        else
			free_program_var(rVar, "S path ", "is defined more than one time\n");
    }
    else if (!ft_strcmp(s, "F"))
    {
        if (!rVar->F)
            rVar->F = path;
        else
			free_program_var(rVar, "F path ", "is defined more than one time\n");
    }
}

void	get_all_texture_path(char *s, char *path, t_map *rVar)
{
	get_NS_texture_path(s, path, rVar);
	get_WA_texture_path(s, path, rVar);
	get_sprite_floor_tex_path(s, path, rVar);
}
