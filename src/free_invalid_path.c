#include "../include/cub3d.h"

void	free_program_str(t_map *r, char *s1, char *s2, char *s)
{
	free_str(s1);
	free_str(s2);
	free_program_var(r, "Wrong map:", s);
}
