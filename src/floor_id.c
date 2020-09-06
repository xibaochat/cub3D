#include "../include/cub3d.h"

int		floor_color_is_number(t_map *r, char *line)
{
	int	i;

	i = 1;
	while (line[i])
	{
		if (is_space(line[i])|| ft_isdigit(line[i])
			|| line[i] == ',')
			i++;
		else
			free_program_var(r, "Invalid char in floor value\n", NULL);
	}
	return (1);
}

int		is_floor_id(t_map *r, char *line)
{
	int	i;

	i = 0;
	if (line[0] != 'F')
		return (0);
	return (1);
}
