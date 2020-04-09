/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 03:32:29 by xinwang           #+#    #+#             */
/*   Updated: 2020/04/09 12:08:42 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int release(int keycode, t_map	*rVar)
{
	if (keycode == ESCAPE_KEY)
	{
		system("killall afplay");
		exit(0);
	}
	else if (keycode == W_KEY)
		rVar->open_up = 0;
	else if (keycode == S_KEY)
		rVar->open_down = 0;
	else if (keycode == A_KEY)
		rVar->open_A = 0;
	else if (keycode == D_KEY)
		rVar->open_D = 0;
	else if (keycode == LEFT_ARROW_KEY)
		rVar->open_left = 0;
	else if (keycode == RIGHT_ARROW_KEY)
		rVar->open_right = 0;
	else if (keycode == SHOOTING)
		rVar->shooting = 0;
	else if (keycode == COUTEAU)
		rVar->couteau = 0;
	rVar->nb_press = 0;
	return (0);
}

int mouse_press_hook(int mouse_code,int x, int y,  t_map *rVar)
{
	if (mouse_code == 1)
		rVar->shooting = 1;
	if (mouse_code == 2)
		rVar->open_right = 1;
	return (0);
}

int mouse_release_hook(int mouse_code, int x, int y, t_map *rVar)
{
	if (mouse_code == 1)
		rVar->shooting = 0;
	if (mouse_code == 2)
		rVar->open_right = 0;
	return (0);
}
