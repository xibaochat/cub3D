/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_cover.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 13:45:04 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 20:48:05 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	click_to_enter(int mouse_code, int x, int y, t_map *rvar)
{
	if (mouse_code > 0 && x && y)
	{
		mlx_destroy_window(rvar->mlx_ptr, rvar->win_ptr);
		start(rvar);
	}
	return (0);
}

int			close_red_button(t_map *rvar, void *p)
{
	if (p)
		free_program_var(rvar, "The program is closed\n", NULL);
	return (-1);
}

static int	funct(int keycode, t_map *rvar)
{
	if (keycode != ESCAPE)
		ft_putstr("Please click to play :)\n");
	if (keycode == ESCAPE)
		free_program_var(rvar, "The program is closed\n", NULL);
	return (0);
}

void		show_cover_menu(t_map *r)
{
	int		w;
	int		h;
	void	*cover_img;

	if (!(r->win_ptr = mlx_new_window(r->mlx_ptr, 1280, 720, "CAT BATTLE")))
		free_program_var(r, "Malloc fail in creating window", NULL);
	cover_img = mlx_xpm_file_to_image(r->mlx_ptr, \
	"textures/cat_menu.xpm", &w, &h);
	if (!cover_img)
		free_program_var(r, "Fail xpm file to image\n", NULL);
	mlx_put_image_to_window(r->mlx_ptr, r->win_ptr, cover_img, 0, 0);
	mlx_key_hook(r->win_ptr, funct, r);
	mlx_mouse_hook(r->win_ptr, click_to_enter, r);
	mlx_hook(r->win_ptr, 17, (1L << 17), close_red_button, r);
	mlx_loop(r->mlx_ptr);
}
