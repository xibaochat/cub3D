/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_from_s.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:54:56 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 14:36:45 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char			*get_next_line_from_s(char *s)
{
	static int	i = 0;
	int			i_origin;
	char		*line;
	int			len;

	if (!s)
	{
		i = 0;
		return (NULL);
	}
	if (!s[i])
		return (NULL);
	i_origin = i;
	len = 0;
	line = NULL;
	while (s[i] && s[i++] != '\n')
		++len;
	line = ft_strnew(len + 1);
	line[len] = '\0';
	ft_strncat(line, s + i_origin, len);
	return (line);
}
