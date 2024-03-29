/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 19:10:21 by xinwang           #+#    #+#             */
/*   Updated: 2020/04/20 08:19:46 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int			no_newline_in_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (0);
	return (1);
}

static int			get_content_from_file(int fd, char **str)
{
	int		nb_read;
	char	*tmp;
	char	*buff;

	tmp = NULL;
	buff = NULL;
	nb_read = nb_read_from_buffer(fd, &buff, &tmp, str);
	if (nb_read <= 0)
		return (nb_read);
	if (*str)
	{
		tmp = ft_strncat(tmp, *str, ft_strlen(*str));
		free_str(*str);
	}
	*str = ft_strncat(tmp, buff, nb_read);
	tmp = NULL;
	free_str(buff);
	if (no_newline_in_str(*str))
		return (get_content_from_file(fd, str));
	return (1);
}

static int			extract_line(char **line, char **str, int *i, int *j)
{
	char	*s;
	char	*s1;
	char	*tmp;

	while ((*str)[*i] && (*str)[*i] != '\n')
		(*i)++;
	if (!(s = ft_strnew(*i + 1)))
		return (-1);
	*line = ft_strncat(s, *str, *i);
	*j = ft_strlen(*str) - *i;
	if (!*j)
	{
		*line = *str;
		return (0);
	}
	if ((s1 = ft_strnew(*j)))
	{
		tmp = ft_strncat(s1, *str + *i + 1, *j - 1);
		free_str(*str);
		*str = tmp;
		return (1);
	}
	return (nigun_static(str, -1));
}

static int			manage_str(char **str, char **line)
{
	int res;
	int	i;
	int	j;

	i = 0;
	j = 0;
	res = 0;
	if ((res = extract_line(line, str, &i, &j) != 1))
	{
		if (res == -1)
			return (nigun_static(str, -1));
		return (nigun_static(str, 0));
	}
	return (1);
}

int					get_next_line(int fd, char **line)
{
	static char *str = NULL;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
	{
		free(str);
		str = NULL;
		return (-1);
	}
	if (no_newline_in_str(str))
	{
		if (get_content_from_file(fd, &str) == -1)
			return (nigun_static(&str, -1));
		if (!str)
		{
			*line = ft_strnew(1);
			return (0);
		}
	}
	return (manage_str(&str, line));
}
