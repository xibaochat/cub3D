/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:19:43 by xinwang           #+#    #+#             */
/*   Updated: 2020/04/20 20:28:53 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include "../libft/libft.h"

//# define MAX_VALID_WIDTH 1920
# define MIN_VALID_WIDTH 250
//# define MAX_VALID_HEIGHT 1080
# define MIN_VALID_HEIGHT 250
# define NB_SPRITE 6
# define BUFFER_SIZE 1
# define ORIGIN_SIZE 20

# if __APPLE__
#  define MOVE_SPEED 0.065
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
#  define ENTER 65293
#  define ESCAPE 65307
#  define MOVE_SPEED 0.065
#  define ROT_SPEED 0.030
#  define W_KEY 119
#  define A_KEY 97
#  define S_KEY 115
#  define D_KEY 100
#  define LEFT_ARROW_KEY 65361
#  define RIGHT_ARROW_KEY  65363
#  define ESCAPE_KEY 65307
#  define SHOOTING 65507
#  define COUTEAU 113
# endif

# define NB_WEAPONS 2
# define MACHINE_GUN_ID 0
# define COUTEAU_ID 1
# define POTATO_ID 2
# define BAD_CAT_ID 4
# define TNT 7
# define WALL_ID 1

typedef struct		s_color
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}					t_color;

typedef struct		s_spr
{
	struct s_prop	*origin_sprite;
	void			*img;
	char			*addr;
	int				nb_tex;
	double			x;
	double			y;
	int				x_map;
	int				y_map;
	double			sprite_x;
	double			sprite_y;
	double			inv_det;
	double			transform_x;
	double			transform_y;
	int				sprite_screen_x;
	int				sprite_height;
	int				draw_start_y;
	int				draw_end_y;
	int				sprite_width;
	int				draw_start_x;
	int				draw_end_x;
	int				stripe;
	int				tex_x;
	int				hitpoint;
}					t_spr;

typedef struct		s_prop
{
	char			*path;
	int				height;
	int				width;
	void			*img;
	char			*addr;
	void			*img1;
	char			*addr1;
	int				bpp;
	int				s_l;
	int				endian;
	int				nb_occur;
	float			*buffer;
	t_spr			*indi_spr;
}					t_prop;

typedef struct		s_bad_cat
{
	char			*path;
}					t_bad_cat;

typedef struct		s_weap
{
	char			id;
	void			**tex;
}					t_weap;

typedef struct		s_roll_cat
{
	char			*path;
	int				nb_tex;
}					t_roll_cat;

typedef struct		s_texture
{
	void			*img;
	char			*addr;
	int				w;
	int				h;
}					t_texture;

typedef struct		s_die
{
	int				hit;
	int				x;
	int				y;
}					t_die;

typedef struct		s_door
{
	char			*path;
	int				nb_tex;
}					t_door;

typedef	struct		s_map
{
	int				d;
	int				k;
	double			*sprite_distance;
	int				nb_spr;
	int				save_bmp;
	int				round;
	int				mutant_tex;
	t_door			*door;
	int				nb_door;
	t_texture		*textures;
	int				couteau;
	int				nb_roll_cat;
	t_roll_cat		*roll_cat;
	t_bad_cat		*bad_cat;
	int				nb_bad_cat;
	void			**hitpoint_img;
	t_prop			*all_spr;
	t_weap			*weaps;
	int				shooting;
	int				nb_press;
	int				nb_weap_tex;
	t_die			enemy;
	t_bad_cat		*mutant;
	int				nb_mutant;
	int				lucky_value;
	void			*cat_img;
	int				cat_bpp;
	int				s_l_cat;
	int				num_cat;
	t_spr			*cats;
	float			*cat_buffer;
	int				hitpoint;
	int				score;
	double			new_pos_x;
	double			new_pos_y;
	void			*turns_img;
	void			*weapon_img;
	void			*score_img;
	t_spr			*spr;
	float			*spr_buffer;
	void			*spr_img_ptr;
	char			*spr_tex;
	int				width_spr;
	int				height_spr;
	int				spr_bpp;
	int				s_l_spr;
	int				num_spr;
	char			player_dir;
	int				width;
	int				height;
	int				resolution;
	int				fd;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*image_ptr;
	char			*addr;
	int				bpp;
	int				size_line;
	int				endian;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				color;
	double			old_dir_x;
	double			old_plane_x;
	int				open_up;
	int				open_down;
	int				open_left;
	int				open_right;
	int				open_a;
	int				open_d;
	int				look_up;
	int				look_down;
	double			rot_speed;
	int				**map;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	int				ceil_has_color;
	t_color			ceil_color;
	t_color			floor_color;
	char			*map_str;
	int				line;
	int				column;
	void			*text_img_ptr;
	char			*texture;
	void			*screen_img;
	int				s_l;
	int				width_texture;
	int				height_texture;
	void			*floor_img_ptr;
	char			*floor_texture;
	int				width_floor;
	int				height_floor;
	int				floor_bpp;
	int				s_l_floor;
	int				width_ceil;
	int				height_ceil;
	float			ray_dir_x0;
	float			ray_dir_y0;
	float			ray_dir_x1;
	float			ray_dir_y1;
	int				p;
	float			pos_z;
	float			row_distance;
	float			floor_step_x;
	float			floor_step_y;
	float			floor_x;
	float			floor_y;
	int				cell_x;
	int				cell_y;
	int				tx;
	int				ty;
	unsigned int	tex_color;
	char			*f;
	int				f_has_color;
	double			tex_x;
	double			tex_y;
	double			step;
	double			tex_pos;
	t_spr			**sprite_order;
}					t_map;

int					is_all_wall(t_map *r, char *str);
int					cal_nb_elem(char *str, int *mark);
int					start_end_has_wall(t_map *r, char *str);
void					check_invalid_alpha(t_map *r, char *str, int *mark);
char				*ft_strnew(int n);
char				*ft_strcat(char *s1, char *s2);
void				integrate_map(t_map *r);
void				print_map(int **map, char *map_str);
void				get_line(t_map *r, char *str);
void				get_column(t_map *r, char *str);
void				new_graph(t_map	*r);
void				draw_walls(t_map *r);
void				init_all_path_and_ind_spr_value(t_map *r);
void				init_wall_tex_info(t_map *r);
void				init_hitpoint_imgs(t_map *r);
void				init_bad_cat(t_map *r);
void				init_hud_imgs(t_map *r);
void				init_roll_cat(t_map *r);
void				init_turns_img(t_map *r);
void				init_cat_img(t_map *r);
void				reset_rayon_var(t_map *r, int x);
void				move_bad_cat(t_map *r);
void				draw_vertical_sprite(t_spr *spr, t_map *r);
void				calculate_side_dist(t_map *r);
void				find_hits(t_map *r, int x);
void				calculate_start_end_point(t_map *r);
void				set_color(t_map *r);
void				put_pixel(int x, t_map *r);
void				draw_sol(t_map r, int x);
void				display_image(int x, t_map *r);
void				move_up(t_map *r);
void				move_down(t_map *r);
void				move_left(t_map *r);
void				move_right(t_map *r);
int					release(int keycode, t_map *r);
int					movement(t_map *r);
void				get_map_as_str(t_map *r, char *first_line);
int					get_next_line(int fd, char **line);
char				*ft_strncat(char *dest, char *src, unsigned int nb);
void				get_map_taille(t_map *r, char *line);
int					nigun_static(char **str, int n);
void				get_final_map(t_map *r, char *file);
int					is_dir_mark(char c);
void				get_player_pos(t_map *r);
void				init_player_dir(char c, t_map *r);
int					manage_rotation_arrow(int keycode, t_map *r);
void				change_left_rotation_dir(t_map *r);
void				change_right_rotation_dir(t_map *r);
void				draw_background(int x, int s, int e, t_map *r, t_color c);
void				ft_error(char				*str, char *s);
int					map_taille_is_valide(t_map *r, char *file);
void				map_is_readable(t_map *r, char *file);
int					path_dir_is_validate(char *line, char *path_dir);
int					valide_texture_path(t_map *r, char *str);
int					ft_strcmp(char *s1, char *s2);
int					get_next_line_from_str(t_map *r, char **str, char **line);
int					atoi_with_index(char *str, int *i, int *j);
int					map_fst_arg_is_invalid(int *i, char *str);
void				init_r_tex_path(t_map *r);
void				draw_floor(t_map *r);
void				get_tex_dir_path(char *line, t_map *r);
int					get_sprites_num(t_map *r);
void				init_spr(t_map *r);
void				draw_sprites(t_map *r);
int					get_sprites_num(t_map *r);
void				draw_ceil(int x, t_map *r);
int					mouse_press_hook(int mouse_code, t_map *r);
int					mouse_release_hook(int mouse_code, t_map *r);
void				check_space_before_id(t_map *r, char *line);
void				validate_all_id_are_set(t_map *r);
int					is_resolution_id(t_map *r, char *line);
int					press(int keycode, t_map *r);
void				get_all_texture_path(char *s, char *path, t_map *r);
void				show_cover_menu(t_map *r);
int					close_red_button(t_map *r, void *p);
void				start(t_map *r);
void				init_raycasting_var(t_map *r);
void				change_char_in_addr_value(t_map *r, char *s2, int j, int k);
void				insert_warn(t_map *r);
void				change_music_selon_turn(t_map	*r);
int					leave_page(int keycode, t_map *r);
int					game_over(t_map *r);
void				lose_game_of_this_turn(t_map *r);
void				put_game_turns_to_window(t_map *r);
void				put_score_to_window(t_map *r);
void				put_weapon_to_win(t_map	*r);
int					get_cats_num(t_map *r);
void				draw_good_cats(t_map *r);
void				init_all_sprites(t_map *r);
void				draw_sprites(t_map *r);
void				init_player_stats(t_map *r);
void				move_roll_cat(t_map *r);
void				set_sprite_img(t_map *r, t_prop *spr, int i);
void				set_curr_sprites_tex(t_map *r);
void				get_indi_sprite_coord(t_spr *spr, t_map *r, int n);
void				set_entity_hitpoint_as_zero(t_map *r, int i, int x, int y);
void				set_sprites_order(t_map *r, t_spr **spr_ord, int nb_spr);
void				manage_sound_based_on_pos(t_map *r);
int					get_wall_texture(t_map *r);
void				init_mutant(t_map *r);
void				init_weapons(t_map *r);
void				init_weapon_texture(t_map *r, t_weap *w, int nt, char *s);
void				put_weapon_to_win(t_map *r);
void				manage_damage(t_map *r);
void				init_enemy_die(t_map *r);
void				decrease_enemy_hitpoint(t_map *r, int hitpoint);
void				init_door(t_map *r);
void				move_door(t_map *r);
void				init_mutan_img(t_map *r);
void				put_lucky_value_to_window(t_map *r);
void				write_bmp(t_map *r);
void				free_program_var(t_map *r, char *s1, char *s2);
void				free_hitpoint(t_map *r);
void				free_spr_img(t_map *r);
void				init_program_var(t_map *r);
char				*get_mutant_tex_path(t_map *r, int j);
void				init_mutan_img(t_map *r);
void				init_origin_sprite(t_prop *spr);
void				init_hp(t_prop *spr);
void				init_origin_sprite(t_prop *spr);
int					cal_nb_obj(char *map_str, int i);
void				replace_pixel_value_floor(t_map *r, char *s2, int j, int k);
void				change_sprite_tex_index(t_map *r);
void				move_vertical_left(t_map *r);
void				move_vertical_right(t_map *r);
void				move_up(t_map *r);
void				move_down(t_map *r);
void				move_left(t_map *r);
void				move_right(t_map *r);
int					wall_collision(double x, double y, int **map);
void				set_new_pos_and_value_after_pick_spr(t_map *r);
int					player_is_knocking_on_wall_or_barrier(t_map *r, double x, \
															double y);
void				inser_hurt(t_map *r, double n1, double n2);
int					nice_job(t_map *r);
void				final_message(char *s1, char *s2);
void				write_bmp(t_map *rvar);
int					save_bmp(t_map *r);
void				free_str(char *str);
char				*ft_strclone(char *s);
void				first_init_sprite(t_map *r);
void        		get_remove_space_str(char **str);
int					map_info_id_all_get(t_map *r);
void				extract_map_as_str(char **line, t_map *r);
void				get_map_size_tex_dir_path(char *line, t_map *r);
void				free_value(int v, t_map *r);
int					has_invalid_ele_in_map(char *line);
void				validity_map(t_map *r);
void				set_new_map_str(t_map *r, char *str);
int					get_color(t_map *r, char *str, int *i, char c);
void				get_ceil_color(t_map *r, char *p);
void				get_floor_color(t_map *r, char *p);
void				free_program_str(t_map *r, char *s1, char *s2, char *str);
int					is_map_content(char *line);
int					is_ceil_id(t_map *r, char *line);
int					is_floor_id(t_map *r, char *line);
int					floor_color_is_number(t_map *r, char *line);
char				*extract_path_from_line(t_map *r, char *line, int i);
void				get_north_texture_path(char *line, t_map *r);
void				get_south_texture_path(char *line, t_map *r);
void				get_west_texture_path(char *line, t_map *r);
void				get_east_texture_path(char *line, t_map *r);
int					is_wall_texture_id(char *line, t_map *r);
void				draw_floor_if_number(int x, t_map *rvar);
char				*get_next_line_from_s(char *s);

#endif
