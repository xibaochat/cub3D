#include "cub3D.h"

static int  color_index_in_str(int x, int y, int s_l,  t_map *rVar)
{
    return ( s_l * y + x * (rVar->bpp / 8));
}

static void replace_color(t_spr indi_spr, int texX, int texY, int y, t_map *rVar)
{
    int k;
    int j;

	k = color_index_in_str(texX, texY, indi_spr.origin_sprite->s_l, rVar);
	j =  color_index_in_str(indi_spr.stripe, y, rVar->size_line, rVar);
	if ((rVar->endian == 0) && indi_spr.origin_sprite == rVar->all_spr + 5)
	{
		if ((unsigned int)(indi_spr.addr[k]) != 0xFFFFFFEE)
		{
			rVar->addr[j] = indi_spr.addr[k];
			rVar->addr[j + 1] = indi_spr.addr[k + 1];
			rVar->addr[j + 2] = indi_spr.addr[k + 2];
		}
	}
    else if ((rVar->endian == 0) && (unsigned int)indi_spr.origin_sprite->addr[k] != 0x000000)
    {
		rVar->addr[j] = indi_spr.origin_sprite->addr[k];
		rVar->addr[j + 1] = indi_spr.origin_sprite->addr[k + 1];
		rVar->addr[j + 2] = indi_spr.origin_sprite->addr[k + 2];
    }
    else if ((unsigned int)indi_spr.origin_sprite->addr[k] != 0x000000)
    {
        rVar->addr[j + 2] = indi_spr.origin_sprite->addr[k + 2];
        rVar->addr[j + 1] = indi_spr.origin_sprite->addr[k + 1];
        rVar->addr[j] = indi_spr.origin_sprite->addr[k];
    }
}

void draw_vertical_sprite(t_spr *indi_spr, t_map *rVar)
{
    int y;
    int d;
    int texX;
    int texY;

    while (indi_spr->stripe++ < indi_spr->drawEndX - 1)
    {
        texX = (int)((256 * (indi_spr->stripe - (-indi_spr->spriteWidth / 2 + indi_spr->spriteScreenX)) *
					  indi_spr->origin_sprite->width / indi_spr->spriteWidth) / 256);
        if (indi_spr->transformY > 0 && indi_spr->stripe > 0 &&
			indi_spr->stripe < WIDTH && indi_spr->transformY < rVar->spr_buffer[indi_spr->stripe])
        {
            y =  indi_spr->drawStartY;
            while (y++ <  indi_spr->drawEndY - 1)
            {
                d = (y) * 256 - HEIGHT * 128 + indi_spr->spriteHeight * 128;
				texY = ((d * indi_spr->origin_sprite->height) / indi_spr->spriteHeight) / 256;
				replace_color(*indi_spr, texX, texY, y, rVar);
			}
		}
	}
}
