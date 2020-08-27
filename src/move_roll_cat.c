/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_roll_cat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 08:13:19 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 08:13:20 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	move_roll_cat(t_map *rvar)
{
	rvar->roll_cat->nb_tex++;
	if (rvar->roll_cat->nb_tex % 3 == 0)
		rvar->nb_roll_cat++;
	if (rvar->nb_roll_cat == 16)
		rvar->nb_roll_cat = 0;
}
