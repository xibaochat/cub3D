/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 11:14:12 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 11:16:55 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_line(t_map *rvar, char *str)
{
	int i;
	int line;

	line = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			line++;
		i++;
	}
	rvar->line = line + 1;
}

void	get_column(t_map *rvar, char *str)
{
	int i;
	int column;

	i = 0;
	column = -1;
	while (str[i] && str[i] != '\n')
	{
		if (ft_isdigit(str[i]))
			column++;
		i++;
	}
	rvar->column = column + 1;
}

int		get_next_line_from_str(t_map *rvar, char **str, char **line)
{
	char	*s;
	char	*s1;
	char	*tmp;
	int		i;
	int		j;

	if (!*str || !*str[0])
		return (0);
	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if (!(s = ft_strnew(i + 1)))
		return (-1);
	*line = ft_strncat(s, *str, i);
	j = strlen(*str) - i;
	if (!j)
		return (0);
	if ((s1 = ft_strnew(j)))
	{
		tmp = ft_strncat(s1, *str + i + 1, j - 1);
		free_str(*str);
		*str = tmp;
		return (1);
	}
	free_program_var(rvar, "malloc fail", NULL);
	return (-1);
}

void	valid_map_on_everyline(t_map *rvar, char *str)
{
	char	*line;
	int		nb_elem;
	int		tmp;
	int		mark;

	mark = 0;
	get_next_line_from_str(rvar, &str, &line);
	is_all_wall(rvar, line);
	nb_elem = cal_nb_elem(line, &mark);
	while (get_next_line_from_str(rvar, &str, &line) > 0)
	{
		tmp = cal_nb_elem(line, &mark);
		if (nb_elem != tmp)
			free_program_var(rvar, \
		"the column of eachlinein the map is not equal\n", NULL);
		start_end_has_wall(rvar, line);
		has_invalid_alpha(rvar, line);
	}
	is_all_wall(rvar, line);
	if (mark == 0)
		free_program_var(rvar, \
	"player position is not showed in the map\n", NULL);
	if (mark > 1)
		free_program_var(rvar, \
	"player position is showed multiple times\n", NULL);
}
