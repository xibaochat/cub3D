/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_chaque_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 07:18:40 by osshit            #+#    #+#             */
/*   Updated: 2020/04/19 07:20:18 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		ft_error(char *str, char *s)
{
	if (str && ft_strcmp(str, "The program is closed\n")
		&& ft_strcmp(str, "Sorry :(\n")
		&& ft_strcmp(str, "BMP file is saved\n"))
		ft_putstr_fd("Error\n", 2);
	if (str)
		ft_putstr_fd(str, 2);
	if (s)
		ft_putstr_fd(s, 2);
	if (str || s)
		exit(-1);
}
