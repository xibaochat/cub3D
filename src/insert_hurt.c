#include "cub3D.h"

int player_is_knocking_on_wall_or_barrier(t_map *rVar,double new_posX,						\
												  double new_posY)
{
	return(((wall_collision(new_posX, rVar->posY, rVar->map) ||
			  wall_collision(rVar->posX, new_posY, rVar->map)) &&
			 ((rVar->map[(int)new_posX][(int)new_posY] == petit_bomb) ||
			  (rVar->map[(int)new_posX][(int)new_posY] == TNT) ||
			  (rVar->map[(int)new_posX][(int)new_posY] == crazy_cat) ||
			  (rVar->map[(int)new_posX][(int)new_posY] == wall))));
}

void inser_hurt(t_map *rVar, double new_posX, double new_posY)
{
	if (player_is_knocking_on_wall_or_barrier(rVar, new_posX, new_posY))
		insert_warn(rVar);
	if (rVar->round == 0 && rVar->score >= 150 &&
		(int)rVar->new_posX == 19 && (int)rVar->new_posY == 7 &&
		((rVar->lucky_value == (rVar->all_spr + 3)->nb_occur)))
	{
		free_program_var(rVar, NULL, NULL);
		get_final_map(rVar, "maps/my_map02.cub");
		rVar->round++;;
		start(rVar);
	}
}
