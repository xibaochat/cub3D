#include "cub3D.h"

void move_bad_cat(t_map *rVar)
{
    rVar->nb_bad_cat++;
    if (rVar->nb_bad_cat == 30)
        rVar->nb_bad_cat = 0;
}
