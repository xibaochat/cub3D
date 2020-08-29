/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_bar_to_win.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 08:32:20 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 08:32:23 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_lucky_value_to_window(t_map *rvar)
{
	int i;

	i = -1;
	while (++i < rvar->lucky_value)
		mlx_put_image_to_window(rvar->mlx_ptr, rvar->win_ptr, \
	rvar->turns_img, rvar->width - 35 * (i + 2), 25 * (i + 2));
}

void	put_score_to_window(t_map *rvar)
{
	int 	w;
	int 	h;
	char	*n_tmp;

	n_tmp = NULL;
	if (rvar->score_img)
		mlx_destroy_image(rvar->mlx_ptr, rvar->score_img);
	rvar->score_img = mlx_xpm_file_to_image(rvar->mlx_ptr, \
	"textures/score.xpm", &w, &h);
	mlx_put_image_to_window(rvar->mlx_ptr, rvar->win_ptr,	\
	rvar->score_img, 0, rvar->height - 25);
	n_tmp = ft_itoa(rvar->score);
	mlx_string_put(rvar->mlx_ptr, rvar->win_ptr,			\
				   10, rvar->height - 5, 15692404, n_tmp);
	free_str(n_tmp);
	if (rvar->hitpoint >= 100)
		mlx_put_image_to_window(rvar->mlx_ptr, rvar->win_ptr, \
	rvar->hitpoint_img[0], 100, rvar->height - 25);
	else if (rvar->hitpoint >= 50)
		mlx_put_image_to_window(rvar->mlx_ptr, rvar->win_ptr, \
	rvar->hitpoint_img[1], 100, rvar->height - 25);
	else if (rvar->hitpoint >= 25)
		mlx_put_image_to_window(rvar->mlx_ptr, rvar->win_ptr, \
	rvar->hitpoint_img[2], 100, rvar->height - 25);
	else if (rvar->hitpoint != 0 && rvar->hitpoint < 25)
		mlx_put_image_to_window(rvar->mlx_ptr, rvar->win_ptr, \
	rvar->hitpoint_img[3], 100, rvar->height - 25);
}
