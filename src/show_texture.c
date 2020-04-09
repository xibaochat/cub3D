#include "cub3D.h"

/*int ft_key(int k)
{
  if (k == 53)
    exit(-1);
  return (0);
}*/

void show_texture(t_map *rVar)
{
	
  int i;
  int j;
  i = 0;
  j = 0;
  while (rVar->texture[i])
    {
      rVar->addr[j] = rVar->texture[i];
      rVar->addr[j+1] = rVar->texture[i+1];
      rVar->addr[j+2] = rVar->texture[i+2];
      i += (rVar->bpp)/8;
      if ((j + 4 - rVar->s_l) %  (rVar->size_line) == 0)
	j += rVar->size_line - rVar->s_l + 4;
      else
	j += (rVar->bpp)/8;
    }
	/*	i = 0;
		j = s_l;
		int whats_left = size_line - (2 * s_l);
	while (texture[i])
	{
	addr[j] = texture[i];
	addr[j+1] = texture[i+1];
	addr[j+2] = texture[i+2];
	i += bpp/8;
	if ((j + 4 + whats_left) % size_line == 0)
	j += size_line - s_l + 4;
	else
	j += bpp/8;
	}
	write(1, "ok", 2);*/
	//mlx_put_image_to_window (rVar->mlx_ptr, rVar->win_ptr,  screen_img, 0, 0);
	//mlx_key_hook(win_ptr, ft_key, NULL);
	//mlx_loop(mlx_ptr);
}
