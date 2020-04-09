#include "cub3D.h"

void	init_rVar_tex_path(t_map	*rVar)
{
    rVar->NO = NULL;
    rVar->SO = NULL;
    rVar->WE = NULL;
    rVar->EA = NULL;
    rVar->S = NULL;
    rVar->F = NULL;
    rVar->C = NULL;
}

static void cpy_column(int  **map, int i, int   *k, t_map   *rVar)
{
    int j;

    j = 0;
    while (j < rVar->column)
    {
        if (ft_isdigit(rVar->map_str[*k]))
        {
            map[i][j++] = rVar->map_str[*k] - '0';
        }
        else if (rVar->map_str[*k] == 'N' || rVar->map_str[*k] == 'S' ||
                 rVar->map_str[*k] == 'W' || rVar->map_str[*k] == 'E')
        {
            rVar->player_dir = rVar->map_str[*k];
            map[i][j++] = 0;
        }
        (*k)++;
    }
}

void integrate_map(t_map *rVar)
{
    int **map;
    int i;
    int k;

    i = -1;
    k = 0;
    if (!(rVar->map = (int **)malloc(sizeof(int *) * (rVar->line))))
    {
		free_program_var(rVar, "malloc fail:", "rVar->map");
        return ;
    }
	i = -1;
	while (++i < rVar->line)
		rVar->map[i] = NULL;
	i = -1;
    while (++i < rVar->line)
    {
        if (!(rVar->map[i] = (int *)malloc(sizeof(int) * (rVar->column))))
			free_program_var(rVar, "malloc fail:", "rVar->map[i]");
        cpy_column(rVar->map, i, &k, rVar);
        if (rVar->map_str[k] && rVar->map_str[k] == '\n')
            k++;
    }
}

void	get_info_from_map(t_map *rVar)
{
    char    *line;
	int value;

	line = NULL;
    while ((value = get_next_line(rVar->fd, &line)) > 0)
    {
		if (line && line[0])
        {
            check_space_before_id(rVar, line);
            if (ft_isdigit(line[0]))
            {
             	get_map_as_str(rVar, line);
                break;
            }
            if (is_resolution_id(line))
                get_map_taille(rVar, line);
            else
				get_tex_dir_path(line, rVar);
		}
    }
	if (!value)
		free_program_var(rVar, "The map is empty\n", NULL);
}

void    get_final_map(t_map *rVar, char *file)
{
    map_is_readable(rVar, file);
	init_rVar_tex_path(rVar);
    get_info_from_map(rVar);
    valid_map_on_everyline(rVar, rVar->map_str);
    validate_all_id_are_set(rVar);
	get_line(rVar,rVar ->map_str);
    get_column(rVar, rVar->map_str);
    integrate_map(rVar);
}
