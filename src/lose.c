/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lose.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 07:24:10 by osshit            #+#    #+#             */
/*   Updated: 2020/04/19 07:25:09 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		game_over(t_map *rvar)
{
	system("killall afplay");
	system("afplay ./sounds/game_over.mp3 &");
	free_program_var(rvar, "Sorry :(\n", "You lose the game\n");
	return (0);
}

void	final_message(char *s1, char *s2)
{
	ft_putstr(s1);
	ft_putstr(s2);
	exit(-1);
}

int		nice_job(t_map *rvar)
{
	system("killall afplay");
	system("afplay ./sounds/win_cat.mp3 &");
	free_program_var(rvar, "NICE JOB\n", "BEBE CHAT\n");
	return (0);
}
