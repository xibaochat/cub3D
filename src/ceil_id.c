#include "../include/cub3d.h"

int		is_ceil_id(t_map *r, char *line)
{
	int	i;

	i = 0;
	if (line[0] != 'C')
		return (0);
	i++;
	while (line[i])
	{
		if (is_space(line[i])|| ft_isdigit(line[i])
			|| line[i] == ',')
			i++;
		else
		{
			free_str(line);
			free_program_var(r, "Wrong Map\n", NULL);
		}
	}
	return (1);
}
