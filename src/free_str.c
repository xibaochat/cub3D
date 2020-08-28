#include "../include/cub3d.h"

void	free_str(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
}
