/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_weapon_to_win.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 22:00:19 by osshit            #+#    #+#             */
/*   Updated: 2020/04/09 12:35:21 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void bowing_weapon(t_map *rVar)
{
	  char *tex;

    rVar->nb_press++;
    if (rVar->nb_press % 3 == 0)
	{
		system("afplay ./sounds/potato.mp3 &");
        rVar->nb_weap_tex++;
	}
	tex = rVar->weaps[1].tex[rVar->nb_weap_tex];
	mlx_put_image_to_window(rVar->mlx_ptr, rVar->win_ptr, tex, WIDTH - 200, 350);
	if (rVar->nb_weap_tex == 4)
    {
        rVar->nb_weap_tex = 0;
        rVar->nb_press = 0;
    }
	manage_damage(rVar);
}

void shoot_weapon(t_map *rVar)
{
	char *tex;

	rVar->nb_press++;
	if (rVar->nb_press % 3 == 0)
	{
		system("afplay ./sounds/gun_shoot.mp3 &");
		rVar->nb_weap_tex++;
	}
	if (rVar->nb_weap_tex == 0)
		rVar->nb_weap_tex++;
	tex = rVar->weaps[0].tex[rVar->nb_weap_tex];
	mlx_put_image_to_window(rVar->mlx_ptr, rVar->win_ptr, tex, WIDTH / 2 - 300, 145);
	if (rVar->nb_weap_tex == 4)
	{
		rVar->nb_weap_tex = 0;
		rVar->nb_press = 0;
	}
	manage_damage(rVar);
}

void put_weapon_to_win(t_map *rVar)
{
	if (rVar->shooting)
		shoot_weapon(rVar);
	else if (rVar->couteau)
		bowing_weapon(rVar);
	else
		mlx_put_image_to_window(rVar->mlx_ptr, rVar->win_ptr, rVar->weaps[0].tex[0], WIDTH / 2 - 300, 145);
}
