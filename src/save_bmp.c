/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 13:18:20 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 18:47:54 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	write_bmp(t_map *rvar)
{
	if (rvar->save_bmp)
		rvar->save_bmp = 0;
	if (!save_bmp(rvar))
		free_program_var(rvar, "failed rendering", NULL);
}
