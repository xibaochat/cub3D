#include "cub3D.h"

void free_hitpoint(t_map *rVar)
{
	if (rVar->hitpoint_img)
	{
		free(rVar->hitpoint_img);
		rVar->hitpoint_img = NULL;
	}
}

void free_weapons(t_map *rVar)
{
	int i;
	int j;

	i = -1;
	if (rVar->weaps)
	{
		while (++i < NB_WEAPONS)
		{
			if ((rVar->weaps + i)->tex)
			{
				free(rVar->weaps[i].tex);
				rVar->weaps[i].tex = NULL;
			}
		}
		free(rVar->weaps);
		rVar->weaps = NULL;
	}
}

void free_sprites_selon_type_spr(t_map *rVar)
{
	int i;

	i = -1;
	if (rVar->all_spr)
	{
		while (++i < NB_SPRITE)
		{
			if ((rVar->all_spr + i)->indi_spr)
			{
				free((rVar->all_spr + i)->indi_spr);
				(rVar->all_spr + i)->indi_spr = NULL;
			}
		}
		free(rVar->all_spr);
		rVar->all_spr = NULL;
	}
}

void free_sprite_order(t_map *rVar)
{
	if (rVar->sprite_order)
	{
		free(rVar->sprite_order);
		rVar->sprite_order = NULL;
	}
}

void free_spr_img(t_map *rVar)
{
	if (rVar->bad_cat)
	{
		free(rVar->bad_cat);
		rVar->bad_cat = NULL;
	}
	if (rVar->roll_cat)
	{
		free(rVar->roll_cat);
		rVar->roll_cat = NULL;
	}
	if (rVar->door)
	{
		free(rVar->door);
		rVar->door = NULL;
	}
	free_weapons(rVar);
	free_sprites_selon_type_spr(rVar);
}
