#include "cub3D.h"

void put_int_in_char(unsigned char *header, int index, int nb)
{
	header[index] =  (unsigned char)(nb);
	header[index + 1] =  (unsigned char)(nb >> 8);
	header[index + 2] =  (unsigned char)(nb >> 16);
	header[index + 3] =  (unsigned char)(nb >> 24);
}

int write_header(int fd, int filesize, t_map *rVar)
{
	static unsigned char header[54];
	int index;

	index = 0;
	ft_bzero(header, 54);
	header[0] = 'B';
	header[1] = 'M';
	header[10] = 54;
	put_int_in_char(header, 2, filesize);
	header[14] = 40;
	header[26] = 1;
	header[28] = 24;
	put_int_in_char(header, 18, WIDTH);
	put_int_in_char(header, 22, HEIGHT);
	return(write(fd, header, 54));
}

int		get_pixel(t_map *rVar, unsigned int x, unsigned int y)
{
	int	color;

	color = *(int*)(rVar->addr + (rVar->size_line * y + (rVar->bpp * x /8)));
	return ((color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF));
}

int write_data(int fd, t_map *rVar)
{
	int color;
	int j;
	int i;

	i = HEIGHT;
	while (i-- > 0)
	{
		j = 0;
		while (j < WIDTH)
		{
			color = get_pixel(rVar, j, i);
			write(fd, &color, 3);
			j++;
		}
	}
	return (1);
}

int save_bmp(t_map *rVar)
{
	int fd;
	int filesize;

	filesize = 54 + 3 * WIDTH * HEIGHT;
	ft_putstr("BMP is ongoing saving...\n");
	if ((fd = open("my_image.bmp", O_WRONLY | O_CREAT | O_TRUNC,
				   S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
		return (0);
	if (!write_header(fd, filesize, rVar))
		return (0);
	if (!write_data(fd, rVar))
		return (0);
	close(fd);
	free_program_var(rVar,"BMP file is saved\n", NULL);
	return (1);
	exit(0);
}

void write_bmp(t_map *rVar)
{
	int fd;

	if (rVar->save_bmp)
		rVar->save_bmp = 0;
	if (!save_bmp(rVar))
		free_program_var(rVar,"failed rendering", NULL);
}
