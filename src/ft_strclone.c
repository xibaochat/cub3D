#include "../include/cub3d.h"

char	*ft_strclone(const char *s)
{
	char *clone;

	clone = NULL;
	if (!s)
		return (NULL);
	if (!(clone = ft_strnew(ft_strlen(s) + 1)))
		return (NULL);
	return (ft_strncat(clone, s, ft_strlen(s)));
}
