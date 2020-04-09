/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:28:45 by xinwang           #+#    #+#             */
/*   Updated: 2019/10/18 04:21:22 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	char			*ptr;
	unsigned int	i;
	unsigned int	lens;

	str = (char *)s;
	if (!s || !f)
		return (NULL);
	i = 0;
	lens = ft_strlen(str);
	ptr = (char *)malloc(sizeof(char) * (lens + 1));
	if (!ptr)
		return (NULL);
	ptr[lens] = '\0';
	while (i < lens)
	{
		ptr[i] = (*f)(i, str[i]);
		i++;
	}
	return (ptr);
}
