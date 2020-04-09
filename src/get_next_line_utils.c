/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
 /*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 19:10:21 by xinwang           #+#    #+#             */
/*   Updated: 2020/02/25 22:47:55 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	lens;
	unsigned int	i;

	i = 0;
	lens = ft_strlen(dest);
	while (src[i] && i < nb)
		dest[lens++] = src[i++];
	dest[lens] = '\0';
	return (dest);
}

int		nigun_static(char	**str, int return_value)
{
	if (*str)
		free(*str);
	*str = NULL;
	return (return_value);
}
