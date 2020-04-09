#include "cub3D.h"

void init_door(t_map *rVar)
{
    int i;
	char *s;
	char *s1;
	int w;
	int h;

    i = -1;
	rVar->nb_door = 0;
    if (!(rVar->door = (t_door*)malloc(sizeof(t_door) * 5)))
        ft_error("malloc door fail", NULL);
	rVar->door->nb_tex = 0;
    while (++i < 5)
    {
		s = ft_strjoin("./textures/door/texture_", ft_itoa(i));
		s1 = ft_strjoin(s, ".xpm");
		free(s);
		if (!s1)
			ft_error("door", NULL);
		rVar->door[i].path = s1;
	}
}
