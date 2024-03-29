/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_shift_dir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 09:34:30 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 18:45:31 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	change_left_rotation_dir(t_map *rvar)
{
	char c;
	char d;

	c = rvar->player_dir;
	if (c == 'E')
		d = 'N';
	else if (c == 'N')
		d = 'W';
	else if (c == 'W')
		d = 'S';
	else
		d = 'E';
	init_player_dir(d, rvar);
}

void	change_right_rotation_dir(t_map *rvar)
{
	char c;
	char d;

	c = rvar->player_dir;
	if (c == 'E')
		d = 'S';
	else if (c == 'N')
		d = 'E';
	else if (c == 'W')
		d = 'N';
	else
		d = 'W';
	init_player_dir(d, rvar);
}
