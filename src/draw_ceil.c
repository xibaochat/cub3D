#include "cub3D.h"

void	draw_ceil(int x, t_map *rVar)
{
	int y;
	int j;
	unsigned int color;

	y = 0;
	while (y++ < rVar->drawStart)
	{
		j = y * rVar->size_line + x* (rVar->bpp/8);
		if (rVar->endian == 0)
		{
			rVar->addr[j] =  rVar->ceil_color.r;
            rVar->addr[j + 1]=  rVar->ceil_color.g;
            rVar->addr[j + 2] =  rVar->ceil_color.b;
		}
		else
		{
			rVar->addr[j] =  rVar->ceil_color.b;
			rVar->addr[j + 1]=  rVar->ceil_color.g;
			rVar->addr[j + 2] =  rVar->ceil_color.r;
		}
	}
}
