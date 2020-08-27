/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:38:58 by xinwang           #+#    #+#             */
/*   Updated: 2020/04/06 06:06:40 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	set_start_index(char *str, int *i)
{
	while (str[*i] && is_space(str[*i]))
		(*i)++;
}

int			atoi_with_index(const char *s, int *i)
{
	int		sign;
	int		res;
	char	*str;

	str = (char *)s;
	sign = 1;
	res = 0;
	set_start_index(str, i);
	while (str[*i] && (str[*i] == ' ' || str[*i] == ','))
		(*i)++;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		res = res * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (sign * res);
}
