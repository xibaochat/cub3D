/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_read_from_buffer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 19:10:21 by xinwang           #+#    #+#             */
/*   Updated: 2020/04/20 08:19:46 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	nb_read_from_buffer(int fd, char **buff, char **tmp, char **s)
{
	int nb_read;

	nb_read = 0;
	if (!(*buff = ft_strnew(BUFFER_SIZE + 1)))
		return (-1);
	if ((nb_read = read(fd, *buff, BUFFER_SIZE)) <= 0)
	{
		free_str(*buff);
		return (nb_read);
	}
	(*buff)[nb_read] = '\0';
	if (!(*tmp = ft_strnew(ft_strlen(*s) + nb_read + 1)))
	{
		free_str(*buff);
		return (-1);
	}
	return (nb_read);
}
