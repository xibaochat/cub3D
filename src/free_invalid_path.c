/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_invalid_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:54:56 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 14:36:45 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_program_str(t_map *r, char *s1, char *s2, char *s)
{
	free_str(s1);
	free_str(s2);
	free_program_var(r, "Wrong map:", s);
}
