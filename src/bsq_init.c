/*
** EPITECH PROJECT, 2017
** bsq_display.c
** File description:
** display function
*/

#include "bsq.h"

int check_nb_lines(char *str)
{
	int i = 0;

	while (str[i]) {
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i += 1;
	}
	return (1);
}

int get_nb_lines(char *path)
{
	int fd;
	int i = 0;
	char nb_lines[15];

	if ((fd = open(path, O_RDONLY)) == -1)
		display_error(path, 1);
	while (read(fd, &nb_lines[i], 1) > 0 && nb_lines[i] != '\n' && i < 15)
		i += 1;
	nb_lines[i] = '\0';
	close(fd);
	if (!check_nb_lines(nb_lines) || i == 0 || i == 14) {
		my_putstr("error: bad number on first line\n");
		exit(84);
	}
	return (my_atoi(nb_lines));
}

int get_nb_cols(char *path)
{
	int i = 0;
	char tmp;
	int fd;

	if ((fd = open(path, O_RDONLY)) == -1)
		display_error(path, 1);
	while (read(fd, &tmp, 1) > 0 && tmp != '\n');
	while (read(fd, &tmp, 1) > 0 && tmp != '\n')
		i += 1;
	if ((close(fd)) == -1)
		display_error(path, 3);
	return (i);
}

char *load_file(char *path)
{
	int fd;
	char tmp;
	char *buff = malloc(sizeof(char) * (BUFF_SIZE + 1));
	int offset = 0;
	int len;

	if ((fd = open(path, O_RDONLY)) == -1)
		display_error(path, 1);
	while (read(fd, &tmp, 1) > 0 && tmp != '\n');
	while ((len = read(fd, buff, BUFF_SIZE - offset)) > 0)
		offset += len;
	buff[offset] = '\0';
	if (len < 0)
		display_error(path, 2);
	return (buff);
}

map_t *init_map(char *path)
{
	map_t *new = NULL;

	new = malloc(sizeof(*new));
	if (!new)
		exit(84);
	new->nb_cols = get_nb_cols(path);
	new->nb_lines = get_nb_lines(path);
	new->grid = load_file(path);
	new->start = 0;
	new->size = 0;
	return (new);
}
