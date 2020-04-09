#include "cub3D.h"

void	map_is_readable(t_map	*rVar, char *file)
{
	rVar->fd = open(file, O_RDONLY);
	if (rVar->fd == -1)
		ft_error("the map does not exit", NULL);
}

int		valide_texture_path(t_map *rVar, char *str)
{
	int	fd;

	fd = open(str, O_DIRECTORY);
	if (fd >= 3)
	{
		close(fd);
		free_program_var(rVar, str, ": Is a directory\n");
	}
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		free_program_var(rVar, str, ": No such file\n");
	}
	close(fd);
	return (1);
}
