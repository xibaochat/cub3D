#include "cub3D.h"

char *add_first_line(t_map *rVar, char *line)
{
    char *s;

    if (!(s = (char *)malloc(sizeof(char) *ft_strlen(line) + 2)))
        free_program_var(rVar, "can't integrate this line in map", line);
    ft_strcat(s, line);
    ft_strcat(s, "\n");
    return (s);
}

static char *read_from_buffer(t_map *rVar, char *fst_line)
{
    int     nb_read;
    char    buffer[1000];
    char    *s1;

    s1 = NULL;
    nb_read = 0;
    while ((nb_read = read(rVar->fd, buffer, 10)) > 0)
    {
        buffer[nb_read] = '\0';
        if (!(s1 = ft_strnew(ft_strlen(fst_line) + nb_read + 1)))
        {
            free(fst_line);
            free_program_var(rVar, "fail malloc to map str", NULL);
        }
        if (fst_line)
        {
            ft_strcat(s1, fst_line);
            free(fst_line);
        }
        ft_strcat(s1, buffer);
        fst_line = s1;
    }
    return (s1);
}

void get_map_as_str(t_map *rVar, char *first_line)
{

    char    *s1;

    first_line = add_first_line(rVar, first_line);
    s1 = read_from_buffer(rVar, first_line);
    if (!s1)
        free_program_var(rVar, "it is an empyrt map", NULL);
    rVar->map_str = s1;
    close(rVar->fd);
}
