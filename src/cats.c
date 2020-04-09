#include "cub3D.h"

int  get_cats_num(t_map *rVar)
{
	int i;
	char *str;

	rVar->num_cat = 0;
	str = rVar->map_str;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '3')
			rVar->num_spr++;
	}
	return (rVar->num_spr);
}

void init_cat(t_map *rVar)
{
	int i;
	int j;
	int	k;

	i = -1;
	k = 0;
	if (!(rVar->cats = (t_cat *)malloc(sizeof(t_cat) * rVar->num_cat)))
		ft_error("mallpc fail", NULL);
	while (++i < rVar->line)
	{
		j = -1;
		while (++j < rVar->column)
		{
			if (rVar->map[i][j] == 3)
			{
				rVar->cats[k].x = i + 0.5;
				rVar->cats[k].y = j + 0.5;
				k++;
			}
		}
	}
}

void sortSprites_cat(int* order, double* dis, int num)
{
	int i;
	int j;
	int tmp_order;
	int tmp_dis;

	i = -1;
	while (++i < num - 1)
	{
		j = -1;
		while (++j < num - i - 1)
		{
			if (dis[j] < dis[j + 1])
			{
				tmp_order = order[j + 1];
				tmp_dis = dis[j + 1];
				order[j + 1] = order[j];
				order[j] = tmp_order;
				dis[j + 1] =  dis[j];
				dis[j] = tmp_order;
			}
		}
	}

}

void calculation_drawing_cats(t_cat *cats, t_map *rVar)
{

        cats->spriteX = cats->x - rVar->posX;
        cats->spriteY = cats->y -rVar->posY;
        cats->invDet = 1.0 / (rVar->planeX * rVar->dirY - rVar->dirX * rVar->planeY);
        cats->transformX =  cats->invDet * (rVar->dirY * cats->spriteX - rVar->dirX * cats->spriteY);
        cats->transformY = cats->invDet * (-rVar->planeY * cats->spriteX + rVar->planeX * cats->spriteY);
        cats->spriteScreenX = ((WIDTH / 2) * (1 + cats->transformX / cats->transformY));
        cats->spriteHeight = abs((int)(HEIGHT / cats->transformY));
        cats->drawStartY = -cats->spriteHeight / 2 + HEIGHT / 2;
        if(cats->drawStartY < 0)
			cats->drawStartY = 0;
        cats->drawEndY = cats->spriteHeight / 2 + HEIGHT / 2;
        if(cats->drawEndY >= HEIGHT)
			cats->drawEndY = HEIGHT - 1;
        cats->spriteWidth = abs((int)(HEIGHT / cats->transformY));
		cats->drawStartX = -cats->spriteWidth / 2 + cats->spriteScreenX;
        if(cats->drawStartX < 0)
			cats->drawStartX = 0;
        cats->drawEndX = cats->spriteWidth / 2 + cats->spriteScreenX;
        if(cats->drawEndX >= WIDTH)
            cats->drawEndX = WIDTH - 1;
        cats->stripe = cats->drawStartX;
}

int  color_index_in_str_cat(int x, int y, int s_l,  t_map *rVar)
{
	return ( s_l * y + x * (rVar->bpp / 8));
}

void replace_color_cat(t_cat cat, int texX, int texY, int y, t_map *rVar)
{
	int k;
	int j;

	k = color_index_in_str_cat(texX, texY, rVar->s_l_cat, rVar);
	j =  color_index_in_str_cat(cat.stripe, y, rVar->size_line, rVar);
	if (rVar->endian == 0 && (unsigned int)rVar->cat_tex[k] != 0x000000)
	{
		  rVar->addr[j] = rVar->cat_tex[k];
		  rVar->addr[j+1] = rVar->cat_tex[k + 1];
		  rVar->addr[j+2] = rVar->cat_tex[k + 2];
	}
	else if ((unsigned int)rVar->cat_tex[k] != 0x000000)
	{
		rVar->addr[j+2] = rVar->cat_tex[k + 2];
		rVar->addr[j+1] = rVar->cat_tex[k + 1];
		rVar->addr[j] = rVar->cat_tex[k];
	}
}

void draw_vertical_sprite_cat(t_cat *cats, t_map *rVar)
{
	int y;
	int d;
	int texX;
	int texY;

	while (cats->stripe++ < cats->drawEndX)
	{
		texX = (int)((256 * (cats->stripe - (-cats->spriteWidth / 2 + cats->spriteScreenX)) * rVar->width_spr / cats->spriteWidth) / 256);
		if (cats->transformY > 0 && cats->stripe > 0 && cats->stripe < WIDTH && cats->transformY < rVar->cat_buffer[cats->stripe])
		{
			y =  cats->drawStartY;
			while (y++ <  cats->drawEndY - 1)
			{
				d = (y) * 256 - HEIGHT * 128 + cats->spriteHeight * 128;
				texY = ((d * rVar->h_cat) / cats->spriteHeight) / 256;
				replace_color_cat(*cats, texX, texY, y, rVar);
		}
	}
}
}
void draw_good_cats(t_map *rVar)
{
	int		i;
	int		sprite_order[rVar->num_cat];
	double	sprite_distance[rVar->num_cat];

	i = -1;
	init_cat(rVar);
	while (++i < rVar->num_cat)
	{
		sprite_order[i] = i;
		sprite_distance[i] = pow((rVar->posX - rVar->cats[i].x), 2) +
			pow((rVar->posY - rVar->cats[i].y), 2);
	}
	sortSprites_cat(sprite_order, sprite_distance, rVar->num_cat);
	i = -1;
	while (++i < rVar->num_cat)
	{
		calculation_drawing_cats(&rVar->cats[sprite_order[i]], rVar);
		draw_vertical_sprite_cat(&rVar->cats[sprite_order[i]], rVar);
	}
}
