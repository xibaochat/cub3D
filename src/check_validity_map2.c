/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity_map2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:54:56 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 14:36:45 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void		is_all_wall_covered(t_map *r)
{
	char	*line;
	int		mark;

	line = NULL;
	mark = 0;
	while ((line = get_next_line_from_s(r->map_str)))
	{
		if (has_invalid_ele_in_map(line))
		{
			free_str(line);
			free_program_var(r, "Wrong Map\n", NULL);
		}
		check_invalid_alpha(r, line, &mark);
		if (has_invalid_ele_in_map(line) || mark > 1)
		{
			free_str(line);
			free_program_var(r, "Wrong Map\n", "\n");
		}
		free_str(line);
	}
}

static void		check_map_is_closed(t_map *r, char *map_str)
{
	int	i;

	i = -1;
	while (map_str[++i])
	{
		if (map_str[i] != '1' && map_str[i] != '\n' && map_str[i] != ' '
			&& (((map_str[i + 1] && (map_str[i + 1] == ' '
			|| map_str[i + 1] == '\n'))
			|| (i > 0 && (map_str[i - 1] == ' ' || map_str[i - 1] == '\n')))))
			free_program_var(r, "Wrong Map\n", NULL);
		if (map_str[i] == '\n' && map_str[i + 1] && map_str[i + 1] == '\n')
			free_program_var(r, "Wrong Map\n", NULL);
	}
	return ;
}

static int		get_last_line_index(char *s)
{
	int	i_beg_line;
	int	i;

	i_beg_line = 0;
	i = -1;
	while (s[++i])
		if (s[i] == '\n' && s[i + 1] && s[i + 1] != '\0' && s[i + 1] != '\n')
			i_beg_line = i + 1;
	return (i_beg_line);
}

static void		validate_first_and_last_walls_are_closed(t_map *r, char *m_str)
{
	int	i;

	i = -1;
	while (m_str[++i] != '\n')
		if (m_str[i] != '1' && m_str[i] != ' ')
			free_program_var(r, "Map is not closed on first line\n", NULL);
	i = get_last_line_index(m_str) - 1;
	while (m_str[++i] && m_str[i] != '\n')
		if (m_str[i] != '1' && m_str[i] != ' ')
			free_program_var(r, "Map is not closed on last line\n", NULL);
}

void			validity_map(t_map *r)
{
	if (!r->map_str)
		free_program_var(r, "Map content is empty\n", NULL);
	check_map_is_closed(r, r->map_str);
	is_all_wall_covered(r);
	validate_first_and_last_walls_are_closed(r, r->map_str);
}
