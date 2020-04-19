/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 13:32:11 by xinwang           #+#    #+#             */
/*   Updated: 2020/04/17 13:33:00 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	display_image(int x, t_map *r)
{
	int	i;
	int	j;

	i = r->drawStart;
	while (i++ < r->drawEnd)
	{
		j = i * r->size_line + x * (r->bpp) / 8;
		if (r->endian)
		{
			r->addr[j] = r->color;
			r->addr[j + 1] = r->color >> 8;
			r->addr[j + 2] = r->color >> 16;
		}
		else
		{
			r->addr[j] = r->color >> 16;
			r->addr[j + 1] = r->color >> 8;
			r->addr[j + 2] = r->color;
		}
	}
	mlx_put_image_to_window(r->mlx_ptr, r->win_ptr, r->image_ptr, 0, 0);
}
