#include "cub3D.h"

void display_image(int x, t_map *rVar)
{
  int	i;
  int	j;
  i = rVar->drawStart;
  while (i++ < rVar->drawEnd)
    {
      j = i * rVar->size_line + x * (rVar->bpp) / 8;
      if (rVar->endian)
	{
	  rVar->addr[j] = rVar->color;
	  rVar->addr[j + 1] = rVar->color >> 8;
	  rVar->addr[j + 2] = rVar->color >> 16;
	}
      else
	{
	  rVar->addr[j] = rVar->color >> 16;
	  rVar->addr[j + 1] = rVar->color >> 8;
	  rVar->addr[j + 2] = rVar->color;
	}
    }
  mlx_put_image_to_window(rVar->mlx_ptr, rVar->win_ptr, rVar->image_ptr, 0, 0);
}
