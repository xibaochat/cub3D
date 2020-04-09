#include "cub3D.h"

void init_roll_cat(t_map *rVar)
{
	int w;
	int h;
	int i;
	char *s;
	char *s1;

	i = -1;
	rVar->nb_roll_cat = 0;
	rVar->roll_cat = (t_roll_cat *)malloc(sizeof(t_roll_cat) * 16);
	rVar->roll_cat->nb_tex = 0;
	while (++i <= 15)
	{
		s = ft_strjoin("./textures/texture_", ft_itoa(i));
		s1 = ft_strjoin(s, ".xpm");
		free(s);
		rVar->roll_cat[i].path = ft_strnew(ft_strlen(s1) + 1);
		rVar->roll_cat[i].path = ft_strcat(rVar->roll_cat[i].path, s1);
	}
}
