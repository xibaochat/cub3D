/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_sound_based_on_pos.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 11:23:15 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 11:23:32 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	manage_sound_based_on_pos(t_map *r)
{
	if (r->map[(int)r->new_posX][(int)r->new_posY] == 3)
		system("afplay ./sounds/miao.mp3 &");
	else if (r->map[(int)r->new_posX][(int)r->new_posY] == 4)
		system("afplay ./sounds/badcat_miao.mp3 &");
	else if (r->map[(int)r->new_posX][(int)r->new_posY] == 5)
		system("afplay ./sounds/rollcat.mp3 &");
	else if (r->map[(int)r->new_posX][(int)r->new_posY + 3] == 6)
		system("afplay ./sounds/guzheng.mp3 &");
}
