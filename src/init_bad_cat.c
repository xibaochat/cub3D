/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bad_cat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 07:48:48 by osshit            #+#    #+#             */
/*   Updated: 2020/04/19 07:50:00 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_bad_cat(t_map *rvar)
{
	int		w;
	int		h;
	int		i;
	char	*s;
	char	*s1;

	i = -1;
	rvar->nb_bad_cat = 0;
	if (!(rvar->bad_cat = (t_bad_cat *)malloc(sizeof(t_bad_cat) * 31)))
		free_program_var(rvar, "Malloc failed of bad_cat\n", NULL);
	while (++i <= 30)
	{
		s = ft_strjoin("./textures/enemies/badcat/bad_cat_", ft_itoa(i));
		s1 = ft_strjoin(s, ".xpm");
		free(s);
		rvar->bad_cat[i].path = ft_strnew(ft_strlen(s1) + 1);
		rvar->bad_cat[i].path = ft_strcat(rvar->bad_cat[i].path, s1);
	}
}
