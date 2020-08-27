/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 09:55:51 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 09:57:16 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*ft_strnew(int n)
{
	int		i;
	char	*s;

	i = 0;
	s = (char	*)malloc(sizeof(char) * n);
	while (i < n)
	{
		s[i] = '\0';
		i++;
	}
	return (s);
}

char	*ft_strcat(char *dest, char *src)
{
	int	lens;
	int	i;

	i = 0;
	lens = ft_strlen(dest);
	while (src[i])
		dest[lens++] = src[i++];
	dest[lens] = '\0';
	return (dest);
}

int		path_dir_is_validate(char *line, char *path_dir)
{
	int	i;

	i = 0;
	while (path_dir[i])
	{
		if (line[i] != path_dir[i])
			ft_error("texture direction in map is invalid", NULL);
		i++;
	}
	if (line[i] != ' ')
		ft_error("texture direction in map is invalid", NULL);
	return (i);
}
