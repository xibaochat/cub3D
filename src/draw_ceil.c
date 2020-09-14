/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 08:30:04 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 18:48:21 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		draw_ceil(int x, t_map *rvar)
{
	int				y;
	int				j;

	y = 0;
	while (y < rvar->draw_start)
	{
		j = y * rvar->size_line + x * (rvar->bpp / 8);
		if (rvar->endian == 1)
		{
			rvar->addr[j] = rvar->ceil_color.r;
			rvar->addr[j + 1] = rvar->ceil_color.g;
			rvar->addr[j + 2] = rvar->ceil_color.b;
		}
		else
		{
			rvar->addr[j] = rvar->ceil_color.b;
			rvar->addr[j + 1] = rvar->ceil_color.g;
			rvar->addr[j + 2] = rvar->ceil_color.r;
		}
		y++;
	}
}
