/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_roll_cat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 07:38:28 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 19:42:59 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_roll_cat(t_map *rvar)
{
	int		i;
	char	*s;
	char	*s1;
	char	*n_tmp;

	s = NULL;
	s1 = NULL;
	n_tmp = NULL;
	i = -1;
	rvar->nb_roll_cat = 0;
	rvar->roll_cat = (t_roll_cat *)malloc(sizeof(t_roll_cat) * 16);
	rvar->roll_cat->nb_tex = 0;
	while (++i <= 15)
	{
		n_tmp = ft_itoa(i);
		s = ft_strjoin("./textures/texture_", n_tmp);
		free_str(n_tmp);
		s1 = ft_strjoin(s, ".xpm");
		free_str(s);
		rvar->roll_cat[i].path = ft_strnew(ft_strlen(s1) + 1);
		rvar->roll_cat[i].path = ft_strcat(rvar->roll_cat[i].path, s1);
		free_str(s1);
	}
}
