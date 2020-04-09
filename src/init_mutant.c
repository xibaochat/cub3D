#include "cub3D.h"

void init_mutant(t_map *rVar)
{
	int w;
	int h;
	int i;
	char *s;
	char *s1;

	rVar->nb_mutant = 0;

/*	i = -1;
	rVar->mutant_tex = 0;

	rVar->mutant = (t_bad_cat *)malloc(sizeof(t_bad_cat) * 5);
	while (++i <= 4)
	{
		s = ft_strjoin("./textures/enemies/mutant/mutant_", ft_itoa(i));
		s1 = ft_strjoin(s, ".xpm");
		free(s);
		rVar->mutant[i].path = ft_strnew(ft_strlen(s1) + 1);
		 rVar->mutant[i].path = ft_strcat(rVar->mutant[i].path, s1);
		 }*/
}
