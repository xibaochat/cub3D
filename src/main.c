/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:46:43 by xinwang           #+#    #+#             */
/*   Updated: 2020/04/09 10:37:24 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void start(t_map *rVar)
{
	init_player_stats(rVar);
	init_all_path_and_ind_spr_value(rVar);
	if (!(rVar->win_ptr = mlx_new_window(rVar->mlx_ptr, WIDTH, HEIGHT, "CAT BATTLE")))
        free_program_var(rVar, "Mlx new win failed\n", NULL);
	new_graph(rVar);
	mlx_hook(rVar->win_ptr, 4, 0, mouse_press_hook, rVar);
	mlx_hook(rVar->win_ptr, 5, 0, mouse_release_hook, rVar);
	mlx_hook(rVar->win_ptr, 2, (1L << 0), press, rVar);
	mlx_hook(rVar->win_ptr, 3, (1L << 1), release, rVar);
	mlx_hook(rVar->win_ptr, 17, (1L << 0), close_red_button, rVar);
	mlx_loop_hook(rVar->mlx_ptr, movement, rVar);
}

void check_argument(t_map *rVar, int ac, char **av)
{
	char *str;

    if (ac == 3 && ft_strcmp(av[2], "--save") == 0)
        rVar->save_bmp =1;
	else
		rVar->save_bmp = 0;
    if (!(ac == 2 || rVar->save_bmp == 1))
        ft_error("the program argument is invalid\n", NULL);
    if (!(str = ft_strnstr(av[1], ".cub", ft_strlen(av[1]))) || ft_strncmp(str, ".cub", 5) != 0)
        ft_error("First argument must end in .cub\nThis is invalid :", ft_strjoin(av[1], "\n"));
}




int main(int ac, char **av)
{
	t_map	rVar;

	check_argument(&rVar, ac, av);
	init_program_var(&rVar);
	get_final_map(&rVar, av[1]);
	if (ac == 2)
		system("afplay ./sounds/avril_14th.mp3 &");
	rVar.round = 0;
	if (!(rVar.mlx_ptr = mlx_init()))
		free_program_var(&rVar, "Mlx initialization failed", NULL);
	if (!rVar.save_bmp)
		show_cover_menu(&rVar);
	else
		start(&rVar);
	return (0);
}
