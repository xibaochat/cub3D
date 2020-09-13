/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_with_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:54:56 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 14:36:45 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	atoi_with_index(char *str, int *i, int *j)
{
	int	res;

	res = 0;
	while (str[*i] && is_space(str[*i]))
		(*i)++;
	if (str[*i] && ft_isdigit(str[*i]))
	{
		(*j)++;
		while (str[*i] && ft_isdigit(str[*i]))
		{
			res = 10 * res + (str[*i] - '0');
			(*i)++;
		}
	}
	return (res);
}
