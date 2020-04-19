/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_roll_cat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 07:38:28 by osshit            #+#    #+#             */
/*   Updated: 2020/04/19 07:39:35 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_roll_cat(t_map *rvar)
{
	int		w;
	int		h;
	int		i;
	char	*s;
	char	*s1;

	i = -1;
	rvar->nb_roll_cat = 0;
	rvar->roll_cat = (t_roll_cat *)malloc(sizeof(t_roll_cat) * 16);
	rvar->roll_cat->nb_tex = 0;
	while (++i <= 15)
	{
		s = ft_strjoin("./textures/texture_", ft_itoa(i));
		s1 = ft_strjoin(s, ".xpm");
		free(s);
		rvar->roll_cat[i].path = ft_strnew(ft_strlen(s1) + 1);
		rvar->roll_cat[i].path = ft_strcat(rvar->roll_cat[i].path, s1);
	}
}
