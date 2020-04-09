#include "cub3D.h"

void init_bad_cat(t_map *rVar)
{
	int w;
	int h;
	int i;
	char *s;
	char *s1;

	i = -1;
	rVar->nb_bad_cat = 0;
	if (!(rVar->bad_cat = (t_bad_cat *)malloc(sizeof(t_bad_cat) * 31)))
		free_program_var(rVar, "Malloc failed of bad_cat\n", NULL);
	while (++i <= 30)
	{
		s = ft_strjoin("./textures/enemies/badcat/bad_cat_", ft_itoa(i));
		s1 = ft_strjoin(s, ".xpm");
		free(s);
		rVar->bad_cat[i].path = ft_strnew(ft_strlen(s1) + 1);
		rVar->bad_cat[i].path = ft_strcat(rVar->bad_cat[i].path, s1);
	}
}
