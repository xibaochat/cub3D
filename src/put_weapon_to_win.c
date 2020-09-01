/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_weapon_to_win.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 22:00:19 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 09:16:42 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	bowing_weapon(t_map *rvar)
{
	char *tex;

	rvar->nb_press++;
	if (rvar->nb_press % 3 == 0)
	{
		//system("afplay ./sounds/potato.mp3 &");
		rvar->nb_weap_tex++;
	}
	tex = rvar->weaps[1].tex[rvar->nb_weap_tex];
	mlx_put_image_to_window(rvar->mlx_ptr, rvar->win_ptr,\
	tex, rvar->width - 200, 350);
	if (rvar->nb_weap_tex == 4)
	{
		rvar->nb_weap_tex = 0;
		rvar->nb_press = 0;
	}
	manage_damage(rvar);
}

void	shoot_weapon(t_map *rvar)
{
	char *tex;

	rvar->nb_press++;
	if (rvar->nb_press % 3 == 0)
	{
		//system("afplay ./sounds/gun_shoot.mp3 &");
		rvar->nb_weap_tex++;
	}
	if (rvar->nb_weap_tex == 0)
		rvar->nb_weap_tex++;
	tex = rvar->weaps[0].tex[rvar->nb_weap_tex];
	mlx_put_image_to_window(rvar->mlx_ptr, rvar->win_ptr, \
	tex, rvar->width / 2 - 300, 145);
	if (rvar->nb_weap_tex == 4)
	{
		rvar->nb_weap_tex = 0;
		rvar->nb_press = 0;
	}
	manage_damage(rvar);
}

void	put_weapon_to_win(t_map *rvar)
{
	if (rvar->shooting)
		shoot_weapon(rvar);
	else if (rvar->couteau)
		bowing_weapon(rvar);
	else
		mlx_put_image_to_window(rvar->mlx_ptr, rvar->win_ptr, \
	rvar->weaps[0].tex[0], rvar->width / 2 - 300, 145);
}
