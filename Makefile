#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/23 01:08:01 by xinwang           #+#    #+#              #
#    Updated: 2020/04/20 20:48:36 by osshit           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = cub3D

SRCS_NAME = calculation_start_end_point.c  draw_sol.c \
			main.c display_image.c   error_message.c\
			put_pixel.c  movement.c release.c manage_map.c \
			utils.c get_next_line.c get_next_line_utils.c player_info.c\
			change_shift_dir.c manage_key_code.c is_valida_map.c map_info.c\
			atoi_with_index.c fst_arg_in_map.c  save_bmp.c \
			draw_ceil.c integrate_map.c press.c get_texture_path.c show_cover.c\
			init_all_major_var.c music.c lose.c put_bar_to_win.c init_all_sprites.c \
			init_life_score_hitpoint.c init_weapons.c init_weapon_texture.c \
			put_weapon_to_win.c new_graph.c draw_walls.c init_bad_cat.c \
			init_roll_cat.c init_hud_imgs.c init_hitpoint_img.c init_wall_tex_infos.c \
			init_life_img.c init_cat_img.c set_sprites_order.c move_bad_cat.c \
			draw_sprites.c draw_vertical_sprite.c move_roll_cat.c set_sprite_img.c \
			set_curr_sprites_tex.c set_entity_hitpoints.c manage_sound_based_on_pos.c \
			manage_damage.c init_enemy_die.c secret_door.c move_door.c \
			bmp.c  free_cub3d_var.c get_map_as_str.c check_validity_map.c get_player_direction.c \
			free_img.c init_program_var_to_null.c init_mutan.c sprite_calculation.c \
			change_sprite_tex_index.c new_coor_calc_vertical_move.c new_coor_non_ver_move.c \
			set_new_pos_and_value_after_pick_spr.c  insert_hurt.c free_str.c ft_strclone.c \
			first_init_sprite.c  remove_space_before_id.c check_map_id.c extract_map_as_str.c \
			 check_validity_map2.c check_validity_map_functions.c


SRCS_PATH = ./src/

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

#SRCSO = $(SRCS_NAME:.c=.o)

HEADER_DIR = ./include

LIBFT_DIR = ./libft

INC_LIBFT = -lft

LIBFT_A = $(LIBFT_DIR)/libft.a

CC = gcc

#CC_FLAGS =  -Wall -Werror -Wextra
CC_FLAGS = -fsanitize=address -g3

# ------ NEW --------
SRCSO = $(SRCS:.c=.o)
MLX_PATH = minilibx-linux/
MLX_LIB = ${MLX_PATH}/libmlx.a

# -------------------

MLX_FLAGS_DEBIAN = -lmlx -lXext -lX11 -lm
MLX_FLAGS_XIBAO = -L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11 -lm
MLX_FLAGS_OSX = -g -I /usr/X11/include -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit
MLX_DIR = ./mlx
MLX_A = $(MLX_DIR)/libmlx.a $(MLX_DIR)/libmlx_Linux.a

all: ${NAME}

$(NAME): libft_compil ${SRCSO} mlx_compil
	${CC} ${CFLAGS}  -I $(HEADER_DIR) -o ${NAME} ${SRCSO} -L ${MLX_PATH} -lmlx -lXext -lX11 -lbsd -lm -L ${LIBFT_DIR}  -lft

linux_compil: libft_compil
	$(CC) -g -c $(CC_FLAGS) -I $(HEADER_DIR) -I $(LIBFT_DIR) $(SRCS)
	$(CC) -g $(MLX_FLAGS_DEBIAN) $(SRCSO) $(LIBFT_A) $(MLX_A) -o $(NAME)

xibao_compil: libft_compil
	$(CC) -c $(CC_FLAGS) -I $(HEADER_DIR) -I $(LIBFT_DIR) $(SRCS)
	$(CC) $(MLX_FLAGS_XIBAO) $(SRCSO) $(LIBFT_A) $(MLX_A) -o $(NAME)

mlx_compil:
	make -C ${MLX_PATH}

libft_compil:
	make -C ./libft all --silent

clean:
	rm -f $(LIBFT_DIR)/*.o
	rm -f $(SRCSO)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_A)
	rm -f ./*~ $(SRCS_PATH)/*~ $(HEADER_DIR)/*~

re: fclean all
