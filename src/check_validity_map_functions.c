#include "../include/cub3d.h"

int		has_invalid_ele_in_map(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != ' ' &&
			line[i] != '2' && line[i] != '3' && line[i] != '4' &&
			line[i] != '5' && line[i] != '6' && line[i] != '7' &&
			line[i] != 'N' && line[i] != 'S' && line[i] != 'E' &&
			line[i] != 'W')
			return (1);
	}
	return (0);
}

static int			get_max_len_of_each_line(char *map_str)
{
	int		lens;
	int		curr_max;
	char	*line;

	curr_max = 0;
	line = NULL;
	get_next_line_from_s(NULL);  // to reset static var
	while ((line = get_next_line_from_s(map_str)))
	{
		lens = ft_strlen(line);
		if (lens > curr_max)
			curr_max = lens;
		free_str(line);
	}
	return (curr_max + 1);
}

char *ft_strnew_with_c(int len, char c)
{
	int		i;
	char	*s;

	i = -1;
	s = ft_strnew(len);
	while (++i < len - 1)
		s[i] = c;
	return (s);
}

char		*get_new_map_line(t_map *r, char *line, int max_lens)
{
	char	*str;
	int		i;

	i = -1;
	str = ft_strnew_with_c(max_lens, '0');
	while (line[++i])
		if (line[i] != ' ')
			str[i] = line[i];
	return (str);
}

void	set_new_map_str(t_map *r, char *map_str)
{
	char 	*new_map;
	char	*new_line_with_zero;
	char	*line;
	int		max_lens;

	line = NULL;
	new_line_with_zero = NULL;
	max_lens = get_max_len_of_each_line(map_str);
	new_map = ft_strnew((r->line) * max_lens + 1);

	get_next_line_from_s(NULL);  // to reset static var
	while ((line = get_next_line_from_s(map_str)))
	{
		if (new_map)
			ft_strcat(new_map, "\n");
		new_line_with_zero = get_new_map_line(r, line, max_lens);
		ft_strcat(new_map, new_line_with_zero);
		free_str(new_line_with_zero);
		free_str(line);
	}
	free_str(map_str);
	r->map_str = new_map;
}
