#include "cub3D.h"

static void sortSprites(t_spr **order, double *dis, int total_nb_sprite)
{
    int i;
    int j;
    t_spr *tmp_order;
    double tmp_dis;

    i = -1;
    while (++i < total_nb_sprite - 1)
    {
        j = -1;
        while (++j < total_nb_sprite - i - 1)
        {
            if (dis[j] < dis[j + 1])
            {
                tmp_order = order[j + 1];
                tmp_dis = dis[j + 1];
                order[j + 1] = order[j];
                order[j] = tmp_order;
                dis[j + 1] =  dis[j];
                dis[j] = tmp_dis;
            }
        }
    }
}

t_spr **get_sprites_order(t_map *rVar, t_spr  **sprite_order, int total_nb_sprite)
{
	int i;
    double  *sprite_distance;

	i = -1;
	sprite_distance = NULL;
	if (!(sprite_distance = (double *)malloc(sizeof(double) * total_nb_sprite)))
		ft_error("malloc failed", NULL);
	while (++i < total_nb_sprite)
	{
		sprite_distance[i] = pow((rVar->posX - sprite_order[i]->x), 2) +
			pow((rVar->posY - sprite_order[i]->y), 2);
	}
	rVar->sprite_distance = sprite_distance;
	sortSprites(sprite_order, sprite_distance, total_nb_sprite);
	return (sprite_order);
}
