#include "../include/cub3d.h"

int is_wall_texture_id(char *line, t_map *r)
{
	char	*str;

	if (line[0] && line[1])
	{
		str = ft_strnew(3);
		str = ft_strncat(str, line, 2);
		if (!ft_strcmp(str, "SO") || !ft_strcmp(str, "NO") || !ft_strcmp(str, "WE") ||
			!ft_strcmp(str, "EA"))
			return (1);
		else
			return (0);
	}
	return (0);
}

int map_info_id_all_get(t_map *r)
{
    if (r->so && r->we && r->no && r->ea
        && r->resolution
        && r->s && r->ceil_has_color
		&& (r->f || r->f_has_color))
        return (1);
    return (0);
}
