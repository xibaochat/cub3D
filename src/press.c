/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 11:48:04 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 11:48:51 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		press(int keycode, t_map *r)
{
	if (keycode == COUTEAU)
		r->couteau = 1;
	if (keycode == SHOOTING)
		r->shooting = 1;
	if (keycode == ESCAPE_KEY)
	{
		system("pkill -9 afplay");
		exit(0);
	}
	if (keycode == W_KEY)
		r->open_up = 1;
	if (keycode == S_KEY)
		r->open_down = 1;
	if (keycode == A_KEY)
		r->open_A = 1;
	if (keycode == D_KEY)
		r->open_D = 1;
	if (keycode == LEFT_ARROW_KEY)
		r->open_left = 1;
	if (keycode == RIGHT_ARROW_KEY)
		r->open_right = 1;
	return (0);
}
