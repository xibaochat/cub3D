/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:23:07 by xinwang           #+#    #+#             */
/*   Updated: 2020/02/18 21:41:30 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	swap_distance(t_bres *bres_var)
{
	int	tmp;

	tmp = bres_var->dx;
	bres_var->dx = bres_var->dy;
	bres_var->dy = tmp;
	bres_var->is_swap  = 1;
}
