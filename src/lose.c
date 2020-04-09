#include "cub3D.h"

int	game_over(t_map *rVar)
{
	system("killall afplay");
	system("afplay ./sounds/game_over.mp3 &");
	free_program_var(rVar, "Sorry :(\n", "You lose the game\n");
	return (0);
}

void final_message(char *s1, char *s2)
{
    ft_putstr(s1);
    ft_putstr(s2);
    exit(-1);
}

int nice_job(t_map *rVar)
{
	system("killall afplay");
	system("afplay ./sounds/win_cat.mp3 &");
	free_program_var(rVar, "NICE JOB\n", "BEBE CHAT\n");
	return (0);
}
