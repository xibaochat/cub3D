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

int			get_max_len_of_each_line(int fd, char *str)
{
	int		lens;
	int		tmp;
	int		i;
	int		value;
	char	*line;

	tmp = 0;
	i = 0;
	line = NULL;
	while ((value = get_next_line(fd, &line)) >= 0 && i < 1)
	{
		if (!value)
			i++;
		if (value > 0)
			lens = ft_strlen(line);
		else
			lens = ft_strlen(line) + 1;
		if (lens > tmp)
			tmp = lens;
		free_str(line);
	}
	return (lens);
}

char		*get_new_map_line(t_map *r, int v, char *line, int max_lens)
{
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	if (v > 0)
		str = ft_strnew(max_lens + 1);
	else
		str = ft_strnew(max_lens);
	while (i < max_lens)
	{
		if (line[i] && line[i] == ' ')
			str[i] = '0';
		else if (line[i])
			str[i] = line[i];
		else if (!line[i] && i < max_lens -1)
			str[i] = '0';
		i++;
	}
	if (v > 0)
		str[i] = '\n';
	return (str);
}

char		*get_new_map_str(t_map *r, char *str)
{
	char 	*s;
	char	*new_line;
	int 	value;
	char	*line;
	int		i;
	int		max_lens;

	i = 0;
	line = NULL;
	new_line = NULL;
	max_lens = get_max_len_of_each_line(r->fd, str);
	s = ft_strnew((r->line) * max_lens + 1);
	while ((value = get_next_line(r->fd, &line)) >= 0 && i < 1)
	{
		if (!value)
			i++;
		new_line = get_new_map_line(r, value, line, max_lens);
		free_str(line);
		s = ft_strcat(s, new_line);
		free_str(new_line);
	}
	return (s);
}
