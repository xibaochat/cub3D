/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_space_before_id.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:46:43 by xinwang           #+#    #+#             */
/*   Updated: 2020/04/20 10:04:00 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	get_start_index(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] == ' ')
		i++;
	return (i);
}

char		*get_new_str(char *str)
{
	char	*new_str;
	int		i;
	int		j;
	int		k;

	j = 0;
	k = get_start_index(str);
	i = ft_strlen(str) - k;
	new_str = ft_strnew(i + 1);
	while (j < i)
		new_str[j++] = str[k++];
	new_str[j] = '\0';
	return (new_str);
}

void		get_remove_space_str(char **str)
{
	char	*new_str;

	new_str = get_new_str(*str);
	free_str(*str);
	*str = new_str;
}
