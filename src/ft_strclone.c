/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osshit <osshit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:54:56 by osshit            #+#    #+#             */
/*   Updated: 2020/04/20 14:36:45 by osshit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*ft_strclone(char *s)
{
	char *clone;

	clone = NULL;
	if (!s)
		return (NULL);
	if (!(clone = ft_strnew(ft_strlen(s) + 1)))
		return (NULL);
	return (ft_strncat(clone, s, ft_strlen(s)));
}
