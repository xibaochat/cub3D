/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:19:43 by xinwang           #+#    #+#             */
/*   Updated: 2020/04/09 13:13:29 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include "libft.h"

# define WIDTH  rVar->width
# define MAX_VALID_WIDTH 1920
# define MIN_VALID_WIDTH 250
# define MAX_VALID_HEIGHT 1080
# define MIN_VALID_HEIGHT 250
# define HEIGHT rVar->height
# define NB_SPRITE 6
# define BUFFER_SIZE 1
# define sign(x) ((x > 0)? 1 : ((x < 0)? -1: 0))
# define ORIGIN_SIZE 20

# if __APPLE__
#  define moveSpeed 0.065
#  define ROT_SPEED 0.040
#  define W_KEY 13
#  define A_KEY 0
#  define S_KEY 1
#  define D_KEY 2
#  define LEFT_ARROW_KEY 123
#  define RIGHT_ARROW_KEY  124
#  define ESCAPE_KEY 53
#  define SHOOTING 256
#  define COUTEAU 12
# elif __linux__
#  define moveSpeed 0.045
#  define ROT_SPEED 0.015
#  define W_KEY 119
#  define A_KEY 97
#  define S_KEY 115
#  define D_KEY 100
#  define LEFT_ARROW_KEY 65361
#  define RIGHT_ARROW_KEY  65363
#  define ESCAPE_KEY 65307
# endif

// ---- WEAPONS ----
# define NB_WEAPONS 2
# define MACHINE_GUN_ID 0
# define COUTEAU_ID 1
# define petit_bomb 2
# define crazy_cat 4
# define TNT 7
# define wall 1
typedef	struct	s_bres
{
	int	i;
	int x;
	int y;
	int dx;
	int	dy;
	int s1, s2;
	int is_swap;
	int D;
}				t_bres;

typedef struct s_color
{
	unsigned int  r;
	unsigned int g;
	unsigned int b;
}				t_color;

typedef struct s_spr
{
	struct s_prop *origin_sprite;
	void *img;
	char *addr;
	int nb_tex;
	double x;
	double y;
	int x_map;
	int y_map;
	double spriteX;
	double spriteY;
	double invDet;
	double transformX;
	double transformY;
	int spriteScreenX;
	int spriteHeight;
	int drawStartY;
	int drawEndY;
	int spriteWidth;
	int drawStartX;
	int drawEndX;
	int stripe;
	int texX;
	int hitpoint;
}			t_spr;

typedef struct s_prop
{
	char *path;
	int height;
	int width;
	void *img;
	char *addr;
	void *img1;
	char *addr1;
	int bpp;
	int s_l;
	int	endian;
	int nb_occur;
	float *buffer;
	t_spr *indi_spr;
}       t_prop;

typedef struct s_bad_cat
{
	char *path;
} t_bad_cat;

typedef struct s_weap {
	char id;
	void **tex;
}				t_weap;

typedef struct s_roll_cat
{
	char *path;
	int nb_tex;
} t_roll_cat;

typedef struct s_texture
{
	void *img;
	char *addr;
	int w;
	int h;
}		t_texture;

typedef struct s_die
{
	int hit;
	int x;
	int y;
} t_die;

typedef struct s_door
{
	char *path;
	int nb_tex;
} t_door;

typedef	struct	s_map
{
	double *sprite_distance;
	int nb_spr;
	int save_bmp;
	int round;
	int mutant_tex;
	t_door *door;
	int nb_door;
	t_texture *textures;
	int couteau;
	int nb_roll_cat;
	t_roll_cat *roll_cat;
	t_bad_cat *bad_cat;
	int nb_bad_cat;
	void **hitpoint_img;
	t_prop  *all_spr;
	t_weap  *weaps;
	int shooting;
	int nb_press;
	int nb_weap_tex;

	t_die enemy;
	t_bad_cat *mutant;
	int nb_mutant;

	int lucky_value;
	void*	cat_img;
	int		cat_bpp;
	int		s_l_cat;
	int		num_cat;
	t_spr   *cats;
	float	*cat_buffer;
	int hitpoint;
	int score;
	double new_posX;
	double new_posY;
	void 	*turns_img;
	void 	*weapon_img;
	void	*score_img;
	t_spr	*spr;
	float	*spr_buffer;
	void	*spr_img_ptr;
	char	*spr_tex;
	int		width_spr;
	int		height_spr;
	int		spr_bpp;
	int		s_l_spr;
	int		num_spr;
	char	player_dir;
	int		width;
	int		height;
	int		fd;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*image_ptr;
	char	*addr;
  	int	bpp;
  	int	size_line;
	int	endian;
	double	posX;//player position;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	cameraX;//x-coordinate in camera space
	double	rayDirX;//viw x coordonee
	double	rayDirY;//viw y coordonee
	int		mapX;//which box of the map we're in
	int		mapY;
	double	sideDistX;//length of ray from current position to next x or y-side
	double	sideDistY;
	double	deltaDistX;//length of ray from one x or y-side to next x or y-side
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;// what direction to step in x or y-direction
	int		stepY;
	int		hit;//was there a wall hit?
	int		side;//was a NS or a EW wall hit?
	int		lineHeight;//Calculate height of line to draw on screen
	int		drawStart;//calculate lowest pixel to fill in current stripe
	int		drawEnd;//calculate highest pixel to fill in current stripe
	int		color;
		//double	moveSpeed;
	double	oldDirX;
	double	oldPlaneX;
	int	open_up;
	int	open_down;
	int	open_left;
	int	open_right;
	int open_A;
	int open_D;
	int look_up;
	int look_down;
	double	rotSpeed;
	int	**map;
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*S;
	t_color	ceil_color;
	char	*map_str;
	int line;
	int column;
  	void	*text_img_ptr;
  	char *texture;
  	void *screen_img;
	int s_l;
	int width_texture;
	int height_texture;
	void *floor_img_ptr;
	char *floor_texture;
	int width_floor;
	int height_floor;
	int floor_bpp;
	int s_l_floor;
	int width_ceil;
	int height_ceil;
	float rayDirX0;
	float rayDirY0;
	float rayDirX1;
	float rayDirY1;
	int p;
	float posZ;
	float rowDistance;
	float floorStepX;
	float floorStepY;
	float floorX;
	float floorY;
	int cellX;
	int cellY;
	int tx;
	int ty;
	unsigned int tex_color;
	char *F;
	char *C;
	double tex_x;
	double tex_y;
	double step;
	double tex_pos;
	t_spr     **sprite_order;

}				t_map;

int is_all_wall(t_map *rVar, char *str);
int cal_nb_elem(char *str, int *mark);
int start_end_has_wall(t_map *rVar, char *str);
int has_invalid_alpha(t_map *rVar, char *str);
char	*ft_strnew(int n);
char	*ft_strcat(char *s1, char *s2);
void	integrate_map(t_map *rVar);
void	print_map(int **map, char *map_str);
void		get_line(t_map *rVar, char *str);
void		get_column(t_map *rVar, char *str);

void	new_graph(t_map	*rVar);
void	draw_walls(void *mlx_ptr, void *win_ptr, t_map *rVar);

void	init_all_path_and_ind_spr_value(t_map *rVar);
void	init_wall_tex_info(t_map *rVar);
void	init_hitpoint_imgs(t_map *rVar);
void	init_bad_cat(t_map *rVar);

void	init_hud_imgs(t_map *rVar);
void	init_roll_cat(t_map *rVar);
void    init_turns_img(t_map *rVar);
void    init_cat_img(t_map  *rVar);

void	reset_rayon_var(t_map *rVar, int x);

void set_sprites_order(t_map *rVar, t_prop *current_prop, int **sprite_order, int j);
void move_bad_cat(t_map *rVar);
void draw_vertical_sprite(t_spr *spr, t_map *rVar);

void	calculate_side_dist(t_map  *rVar);
void	find_hits(t_map *rVar, int x);
void	calculate_start_end_point(t_map *rVar);
void	set_color(t_map *rVar);
void	put_pixel(int x, t_map *rVar);
void	draw_line(void *mlx_ptr, void *win_ptr, int x1, int x2, int y1, int y2, int distance);
void	draw_column(int x1, int x2, int y1, int y2);
void	swap_distance(t_bres *bres_var);
t_bres	init_bres(int x1, int x2, int y1, int y2);
void	draw_sol(t_map rVar, int x);
void	display_image(int x, t_map *rVar);
void    move_up(t_map    *rVar);
void	move_down(t_map *rVar);
void	move_left(t_map *rVar);
void	move_right(t_map *rVar);
int		release(int keycode, t_map  *rVar);
int		movement(t_map *rVar);
void	get_map_as_str(t_map *rVar, char *first_line);
int		get_next_line(int fd, char **line);
char    *ft_strncat(char *dest, char *src, unsigned int nb);
void	get_map_taille(t_map *rVar, char *line);
int		nigun_static(char **str, int);
void	get_final_map(t_map *rVar, char *file);
int		is_dir_mark(char c);
void	get_player_pos(t_map *rVar);
void	init_player_dir(char c, t_map *rVar);
int		manage_rotation_arrow(int keycode, t_map *rVar);
void	change_left_rotation_dir(t_map *rVar);
void	change_right_rotation_dir(t_map *rVar);
void	draw_background(int x, int start_point, int end_point, t_map *rVar, t_color color);
void	ft_error(char	*str, char *s);
int		map_taille_is_valide(t_map  *rVar, char *file);
void	map_is_readable(t_map *rVar, char *file);
int		path_dir_is_validate(char *line, char *path_dir);
int		valide_texture_path(t_map *rVar, char *str);
int		ft_strcmp(char *s1, char *s2);
int		get_next_line_from_str(t_map *rVar, char **str, char **line);
void	valid_map_on_everyline(t_map *rVar, char *str);
int		atoi_with_index(const char *str, int *i);
int		map_fst_arg_is_invalid(int *i, char *str);
void	show_texture(t_map *rVar);
void	init_rVar_tex_path(t_map *rVar);
void	draw_floor(t_map *rVar);
void	get_tex_dir_path(char *line, t_map *rVar);
int		get_sprites_num(t_map *rVar);
void	init_spr(t_map *rVar);
void	draw_sprites(t_map *rVar);
int		get_sprites_num(t_map *rVar);
void	draw_ceil(int x, t_map *rVar);
int		mouse_press_hook(int mouse_code, int x, int y, t_map *rVar);
int		mouse_release_hook(int mouse_code, int x, int y, t_map *rVar);
void	check_space_before_id(t_map *rVar, char *line);
void	validate_all_id_are_set(t_map *rVar);
int		is_resolution_id(char *line);
int     press(int keycode, t_map *rVar);
void    get_all_texture_path(char	*s, char   *path, t_map *rVar);
void    show_cover_menu(t_map *rVar);
int		close_red_button(t_map *rVar, void *param);
void	start(t_map *rVar);
void    init_raycasting_var(t_map *rVar);
void	change_char_in_addr_value(t_map *rVar, char *s2, int j, int k);
void	insert_warn(t_map   *rVar);
void	change_music_selon_turn(t_map	*rVar);
int		leave_page(int keycode, t_map *rVar);
int		game_over(t_map *rVar);
void	lose_game_of_this_turn(t_map   *rVar);
void    put_game_turns_to_window(t_map  *rVar);
void    put_score_to_window(t_map   *rVar);
void	put_weapon_to_win(t_map    *rVar);
int		get_cats_num(t_map *rVar);
void	draw_good_cats(t_map *rVar);
void	init_all_sprites(t_map *rVar);
void	draw_sprites(t_map *rVar);
void init_player_stats(t_map *rVar);
void move_roll_cat(t_map *rVar);
void set_sprite_img(t_map *rVar, t_prop *spr, int i);

void set_curr_sprites_tex(t_map *rVar);

void get_indi_sprite_coord(t_spr *spr, t_map *rVar, int n);
void set_entity_hitpoint(t_map *rVar, int i_sprite, int x, int y, int hitpoint);
t_spr **get_sprites_order(t_map *rVar, t_spr  **sprite_order, int total_nb_sprite);
void manage_sound_based_on_pos(t_map *rVar);
int get_wall_texture(t_map *rVar);

// Mutants
void init_mutant(t_map *rVar);
void mutant_attack_sound(t_map *rVar);
// WEAPONS
void init_weapons(t_map *rVar);
void init_weapon_texture(t_map *rVar, t_weap *weap, int nb_tex, char *weapon_name);
void put_weapon_to_win(t_map *rVar);
void manage_damage(t_map *rVar);
void init_enemy_die(t_map *rVar);
void decrease_enemy_hitpoint(t_map *rVar, int hitpoint);
void init_door(t_map *rVar);
void move_door(t_map *rVar);
void init_mutan_img(t_map *rVar);
void put_lucky_value_to_window(t_map *rVar);
void write_bmp(t_map *rVar);
void free_program_var(t_map *rVar, char *s1, char *s2);
void free_hitpoint(t_map *rVar);
void free_spr_img(t_map *rVar);
void init_program_var(t_map *rVar);
char *get_mutant_tex_path(t_map *rVar, int j);
void init_mutan_img(t_map *rVar);
void init_origin_sprite(t_prop *spr);
void init_hp(t_prop *spr);
void init_origin_sprite(t_prop *spr);
int cal_nb_obj(char *map_str, int i);
void replace_pixel_value_floor(t_map *rVar, char *s2, int j, int k);
void change_sprite_tex_index(t_map *rVar);
void move_vertical_left(t_map *rVar);
void move_vertical_right(t_map *rVar);
void    move_up(t_map    *rVar);
void move_down(t_map *rVar);
void move_left(t_map *rVar);
void move_right(t_map *rVar);
int wall_collision(double x, double y, int **map);
void set_new_pos_and_value_after_pick_spr(t_map *rVar);
int player_is_knocking_on_wall_or_barrier(t_map *rVar,
										  double new_posX , double new_posY);
void inser_hurt(t_map *rVar, double n1, double n2);
int nice_job(t_map *rVar);
void final_message(char *s1, char *s2);
#endif
