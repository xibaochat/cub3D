/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:46:43 by xinwang           #+#    #+#             */
/*   Updated: 2020/04/20 10:04:00 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	start(t_map *rvar)
{
	init_player_stats(rvar);
	if (!(rvar->win_ptr = mlx_new_window(rvar->mlx_ptr, \
	rvar->width, rvar->height, "CAT BATTLE")))
		free_program_var(rvar, "Mlx new win failed\n", NULL);
	init_all_path_and_ind_spr_value(rvar);
	new_graph(rvar);
	mlx_hook(rvar->win_ptr, 2, (1L << 0), press, rvar);
	mlx_hook(rvar->win_ptr, 3, (1L << 1), release, rvar);
	mlx_hook(rvar->win_ptr, 17, (1L << 17), close_red_button, rvar);
	mlx_loop_hook(rvar->mlx_ptr, movement, rvar);
}

void	check_argument(t_map *rvar, int ac, char **av)
{
	char *str;

	if (ac == 3 && ft_strcmp(av[2], "--save") == 0)
		rvar->save_bmp = 1;
	else
		rvar->save_bmp = 0;
	if (!(ac == 2 || rvar->save_bmp == 1))
		ft_error("the program argument is invalid\n", NULL);
	if (!(str = ft_strnstr(av[1], ".cub", ft_strlen(av[1])))
		|| ft_strncmp(str, ".cub", 5) != 0)
		ft_error("First argument must end in .cub\nThis is invalid :",\
		ft_strjoin(av[1], "\n"));
}

int		main(int ac, char **av)
{
	t_map	rvar;

	check_argument(&rvar, ac, av);
	init_program_var(&rvar);
	get_final_map(&rvar, av[1]);
	first_init_sprite(&rvar);
	if (ac >= 2)
	{
		rvar.round = 0;
		if (!rvar.save_bmp)
			show_cover_menu(&rvar);
		else
			start(&rvar);
	}
	return (0);
}
