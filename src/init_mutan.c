#include "cub3D.h"

char *get_mutant_tex_path(t_map *rVar, int j)
{
    char * s;
    int hitpoints;
	char *str;

    hitpoints = rVar->all_spr[5].indi_spr[j].hitpoint;
    if (hitpoints == 100)
        rVar->all_spr[5].indi_spr[j].nb_tex = 0;
    else if (hitpoints >= 75)
        rVar->all_spr[5].indi_spr[j].nb_tex = 1;
    else if (hitpoints >= 50)
    {
        rVar->all_spr[5].indi_spr[j].nb_tex = 2;
        rVar->all_spr[5].indi_spr[j].hitpoint = 7;
    }
    else
    {
        (rVar->all_spr[5].indi_spr[j].nb_tex)++;
        (rVar->all_spr[5].indi_spr[j].hitpoint)--;
    }
    s = ft_strjoin("./textures/enemies/mutant/chest_", ft_itoa(rVar->all_spr[5].indi_spr[j].nb_tex));
	str = ft_strjoin(s, ".xpm");
	free(s);
    return (str);
}

void init_mutan_img(t_map *rVar)
{

    int j;
    char *tex_path;
    t_prop *spr;

    j = -1;
    spr = rVar->all_spr + 5;
    while (++j < spr->nb_occur)
    {
        if (spr->indi_spr[j].hitpoint > 1)
        {
            tex_path = get_mutant_tex_path(rVar, j);
            spr->indi_spr[j].img = mlx_xpm_file_to_image(rVar->mlx_ptr, tex_path,
                                                         &spr->width, &spr->height);
            spr->indi_spr[j].addr = mlx_get_data_addr(spr->indi_spr[j].img,
                                                      &(spr->bpp), &(spr->s_l), &(spr->endian));
        }
        else if (spr->indi_spr[j].hitpoint == 1)
        {
            spr->indi_spr[j].hitpoint = 0;
            rVar->map[spr->indi_spr[j].x_map][spr->indi_spr[j].y_map] = 0;
            rVar->hitpoint += 25;
        }
    }
}
