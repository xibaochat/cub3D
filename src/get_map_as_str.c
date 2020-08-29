/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_as_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 12:46:39 by osshit            #+#    #+#             */
/*   Updated: 2020/04/18 12:47:05 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char		*add_first_line(t_map *rvar, char *line)
{
	char *s;

	s = NULL;
	if (!(s = (char *)malloc(sizeof(char) * ft_strlen(line) + 2)))
		free_program_var(rvar, "can't integrate this line in map", line);
	ft_strcat(s, line);
	ft_strcat(s, "\n");
	return (s);
}

static char	*read_from_buffer(t_map *rvar, char *fst_line)
{
	int		nb_read;
	char	buffer[1000];
	char	*s1;

	s1 = NULL;
	nb_read = 0;
	while ((nb_read = read(rvar->fd, buffer, 10)) > 0)
	{
		buffer[nb_read] = '\0';
		if (!(s1 = ft_strnew(ft_strlen(fst_line) + nb_read + 1)))
		{
			free_str(fst_line);
			free_program_var(rvar, "fail malloc to map str", NULL);
		}
		if (fst_line)
		{
			ft_strcat(s1, fst_line);
			free_str(fst_line);
		}
		ft_strcat(s1, buffer);
		fst_line = s1;
	}
	return (s1);
}

void		get_map_as_str(t_map *rvar, char *first_line)
{
	char	*s1;
	char	*tmp;

	tmp = add_first_line(rvar, first_line);
	free_str(first_line);
	first_line = tmp;
	s1 = read_from_buffer(rvar, first_line);
	if (!s1)
		free_program_var(rvar, "it is an empty map", NULL);
	rvar->map_str = s1;
	close(rvar->fd);
}
