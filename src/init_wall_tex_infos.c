#include "cub3D.h"

static char *get_tex_path(t_map *rVar, int i)
{
	if (!i)
		return (rVar->NO);
	else if (i == 1)
		return (rVar->SO);
	else if (i == 2)
		return (rVar->WE);
	else
		return (rVar->EA);
}

void init_wall_tex_info(t_map *rVar)
{
	int i;

	i = -1;
	if (!(rVar->textures = (t_texture *)malloc(sizeof(t_texture) * 4)))
		free_program_var(rVar, "Wall texture malloc failed\n", NULL);
	while (++i < 4)
	{
		rVar->textures[i].img = mlx_xpm_file_to_image(rVar->mlx_ptr, \
													  get_tex_path(rVar, i), &(rVar->textures[i].w), &(rVar->textures[i].h));
		rVar->textures[i].addr = mlx_get_data_addr(rVar->textures[i].img, \
												   &(rVar->bpp), &(rVar->s_l), &(rVar->endian));
	}

}
